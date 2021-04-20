#include "Visitor.hpp"

#include <exceptions/NotImplementedException.hpp>
#include <exceptions/VariableNotFoundException.hpp>

#include <llvm/Support/Alignment.h>

using namespace antlr4;
using namespace FooLang;

Scope &Visitor::currentScope()
{
    return this->scopes.top();
}

llvm::Function *Visitor::printfPrototype()
{
    auto printf_type = llvm::FunctionType::get(llvm::Type::getVoidTy(this->llvm_context), {llvm::Type::getInt8PtrTy(this->llvm_context)}, true);
    auto func = this->module->getOrInsertFunction("printf", printf_type, llvm::AttributeList().addAttribute(this->llvm_context, 1U, llvm::Attribute::NoAlias));

    return llvm::cast<llvm::Function>(func.getCallee());
}

void Visitor::from_file(std::string path)
{
    std::ifstream stream;
    stream.open(path);

    auto input = new ANTLRInputStream(stream);
    auto lexer = new FooLexer(input);
    auto tokens = new CommonTokenStream(lexer);
    auto parser = new FooParser(tokens);

    this->scopes.push(Scope());

    FooParser::InstructionsContext *context = parser->instructions();
    this->visitInstructions(context);
}

void Visitor::visitInstructions(FooParser::InstructionsContext *context)
{
    auto functionType = llvm::FunctionType::get(llvm::Type::getInt32Ty(this->llvm_context), {}, false);
    auto function = llvm::Function::Create(functionType, llvm::GlobalValue::LinkageTypes::ExternalLinkage, "main", this->module.get());
    auto block = llvm::BasicBlock::Create(builder.getContext());

    block->insertInto(function);
    this->builder.SetInsertPoint(block);

    this->visitStatements(context->statement());

    this->builder.CreateRet(llvm::ConstantInt::get(llvm::Type::getInt32Ty(this->llvm_context), 0, true));
}

void Visitor::visitStatements(const std::vector<FooParser::StatementContext *> &statementContexts)
{
    for (const auto &statementContext : statementContexts)
    {
        this->visitStatement(statementContext);
    }
}

void Visitor::visitStatement(FooParser::StatementContext *context)
{
    if (auto variableDeclarationContext = context->variableDeclaration())
    {
        this->visitVariableDeclaration(variableDeclarationContext);
    }
    else if (auto printStatementContext = context->printStatement())
    {
        this->visitPrintStatement(printStatementContext);
    }
    else
    {
        throw NotImplementedException();
    }
}

void Visitor::visitVariableDeclaration(FooParser::VariableDeclarationContext *context)
{
    auto name = context->VariableName()->getText();
    auto expression = this->visitExpression(context->expression());
    auto type = expression->getType();

    auto alloca = builder.CreateAlloca(type, nullptr, name);

    builder.CreateStore(expression, alloca);

    this->currentScope().setVariable(name, alloca);
}

llvm::Value *Visitor::visitExpression(FooParser::ExpressionContext *context)
{
    if (auto inParenExpressionContext = dynamic_cast<FooParser::InParenExpressionContext *>(context))
    {
        return this->visitExpression(inParenExpressionContext);
    }
    else if (auto unaryNegativeExpressionContext = dynamic_cast<FooParser::UnaryNegativeExpressionContext *>(context))
    {
        return this->visitUnaryNegativeExpression(unaryNegativeExpressionContext);
    }
    else if (auto nameExpressionContext = dynamic_cast<FooParser::NameExpressionContext *>(context))
    {
        return this->visitNameExpression(nameExpressionContext);
    }
    else if (auto literalContext = dynamic_cast<FooParser::LiteralExpressionContext *>(context))
    {
        return this->visitLiteral(literalContext->literal());
    }

    throw NotImplementedException();
}

llvm::Value *Visitor::visitUnaryNegativeExpression(FooParser::UnaryNegativeExpressionContext *context)
{
    auto expression = this->visitExpression(context->expression());
    auto type = expression->getType();

    if (type->isIntegerTy())
    {
        auto zero = llvm::ConstantInt::get(type, 0);
        return builder.CreateSub(zero, expression);
    }

    throw NotImplementedException();
}

llvm::Value *Visitor::visitNameExpression(FooParser::NameExpressionContext *context)
{
    auto name = context->VariableName()->getText();

    auto variable = this->currentScope().getVariable(name);

    if (!variable)
    {
        throw VariableNotFoundException(name);
    }

    return this->builder.CreateLoad(variable->getType()->getPointerElementType(), variable);
}

llvm::Value *Visitor::visitLiteral(FooParser::LiteralContext *context)
{
    if (auto integerLiteralContext = context->integerLiteral())
    {
        return this->visitIntegerLiteral(integerLiteralContext);
    }

    throw NotImplementedException();
}

llvm::Value *Visitor::visitIntegerLiteral(FooParser::IntegerLiteralContext *context)
{
    if (auto zeroLiteralContext = context->ZeroLiteral())
    {
        return llvm::ConstantInt::get(llvm::Type::getInt64Ty(this->llvm_context), 0, true);
    }
    else if (auto decimalLiteralContext = context->DecimalLiteral())
    {
        return llvm::ConstantInt::get(llvm::Type::getInt64Ty(this->llvm_context), std::stol(decimalLiteralContext->getText()), true);
    }
    else if (auto hexadecimalLiteralContext = context->HexadecimalLiteral())
    {
        return llvm::ConstantInt::get(llvm::Type::getInt64Ty(this->llvm_context), std::stol(hexadecimalLiteralContext->getText(), nullptr, 16), true);
    }
    else if (auto binaryLiteralContext = context->BinaryLiteral())
    {
        auto value = binaryLiteralContext->getText();

        // Remove "0x"
        value.erase(0, 2);

        return llvm::ConstantInt::get(llvm::Type::getInt64Ty(this->llvm_context), std::stol(value, nullptr, 2), true);
    }

    throw NotImplementedException();
}

void Visitor::visitPrintStatement(FooParser::PrintStatementContext *context)
{
    std::vector<std::string> formats;
    std::vector<llvm::Value *> args;

    for (auto &expressionContext : context->expression())
    {
        auto value = this->visitExpression(expressionContext);
        auto type = value->getType();

        args.push_back(value);

        if (type->isIntegerTy())
        {
            formats.push_back("%ld");
        }
        else
        {
            throw NotImplementedException();
        }
    }

    std::ostringstream format;
    std::copy(formats.begin(), formats.end(), std::ostream_iterator<std::string>(format, " "));
    auto formatString = format.str() + '\n';

    auto constant = llvm::ConstantDataArray::getString(this->llvm_context, formatString, true);
    auto global = new llvm::GlobalVariable(*this->module, llvm::ArrayType::get(llvm::Type::getInt8Ty(this->llvm_context), formatString.size() + 1), true, llvm::GlobalValue::PrivateLinkage, constant, ".str");
    global->setUnnamedAddr(llvm::GlobalValue::UnnamedAddr::Global);
    global->setAlignment(llvm::Align(1));

    args.insert(args.begin(), builder.CreateGEP(global, {llvm::ConstantInt::get(llvm::Type::getInt64Ty(this->llvm_context), 0),
                                                         llvm::ConstantInt::get(llvm::Type::getInt64Ty(this->llvm_context), 0)}));

    auto function = this->printfPrototype();

    builder.CreateCall(function, args);
}

llvm::Type *Visitor::visitType(FooParser::TypeContext *context)
{
    auto name = context->VariableName()->getText();

    if (name == "i32")
    {
        return llvm::Type::getInt32Ty(this->llvm_context);
    }

    throw NotImplementedException();
}
