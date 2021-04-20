#pragma once

#include "runtime/FooLexer.h"
#include "runtime/FooParserBaseVisitor.h"

#include <llvm/IR/IRBuilder.h>
#include <llvm/Support/raw_ostream.h>
#include <logic/Scope.hpp>
#include <stack>

namespace FooLang
{
class Visitor
{
public:
    llvm::LLVMContext llvm_context;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> module;
    std::stack<Scope> scopes;

    Visitor() : builder(this->llvm_context),
                module(std::make_unique<llvm::Module>("output", this->llvm_context)) {}

    Scope &currentScope();

    void from_file(std::string path);

    llvm::Function *printfPrototype();

    void visitInstructions(FooParser::InstructionsContext *context);

    void visitStatements(const std::vector<FooParser::StatementContext *> &statementContexts);

    void visitStatement(FooParser::StatementContext *context);

    void visitVariableDeclaration(FooParser::VariableDeclarationContext *context);

    llvm::Value *visitExpression(FooParser::ExpressionContext *context);

    llvm::Value *visitUnaryNegativeExpression(FooParser::UnaryNegativeExpressionContext *context);

    llvm::Value *visitNameExpression(FooParser::NameExpressionContext *context);

    llvm::Value *visitLiteral(FooParser::LiteralContext *context);

    llvm::Value *visitIntegerLiteral(FooParser::IntegerLiteralContext *context);

    void visitPrintStatement(FooParser::PrintStatementContext *context);

    llvm::Type *visitType(FooParser::TypeContext *context);
};
} // namespace FooLang
