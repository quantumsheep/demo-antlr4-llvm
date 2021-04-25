#pragma once

#include "runtime/FooLexer.h"
#include "runtime/FooParserBaseVisitor.h"

#include <llvm/IR/IRBuilder.h>
#include <llvm/Support/raw_ostream.h>
#include <logic/Scope.hpp>
#include <vector>

namespace FooLang
{
class Visitor
{
public:
    std::unique_ptr<llvm::LLVMContext> llvm_context;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> module;
    std::vector<Scope> scopes;

    Visitor() : llvm_context(std::make_unique<llvm::LLVMContext>()),
                builder(*this->llvm_context),
                module(std::make_unique<llvm::Module>("output", *this->llvm_context)) {}

    Scope &currentScope();

    llvm::Value *getVariable(const std::string &name);

    void fromFile(const std::string &path);

    llvm::Function *printfPrototype();

    void visitInstructions(FooParser::InstructionsContext *context);

    struct Body
    {
        llvm::BasicBlock *mainBlock = nullptr;
        llvm::BasicBlock *afterBlock = nullptr;
    };

    Body visitBody(FooParser::BodyContext *context, llvm::BasicBlock *afterBlock = nullptr);

    void visitStatements(const std::vector<FooParser::StatementContext *> &statementContexts);

    void visitStatement(FooParser::StatementContext *context);

    void visitVariableDeclaration(FooParser::VariableDeclarationContext *context);

    void visitIfStatement(FooParser::IfStatementContext *context);

    void visitWhileStatement(FooParser::WhileStatementContext *context);

    void visitPrintStatement(FooParser::PrintStatementContext *context);

    llvm::Value *visitExpression(FooParser::ExpressionContext *context);

    llvm::Value *visitUnaryNegativeExpression(FooParser::UnaryNegativeExpressionContext *context);

    llvm::Value *visitNameExpression(FooParser::NameExpressionContext *context);

    llvm::Value *visitBinaryOperation(FooParser::BinaryOperationContext *context);

    llvm::Value *visitBinaryMultiplyOperation(FooParser::BinaryMultiplyOperationContext *context);

    llvm::Value *visitVariableAffectation(FooParser::VariableAffectationContext *context);

    llvm::Value *visitLiteral(FooParser::LiteralContext *context);

    llvm::Value *visitIntegerLiteral(FooParser::IntegerLiteralContext *context);

    llvm::Type *visitType(FooParser::TypeContext *context);
};
} // namespace FooLang
