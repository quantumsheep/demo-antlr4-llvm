
// Generated from /Users/qtmsheep/Development/dev-day-language/src/grammar/FooParser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "FooParserVisitor.h"


/**
 * This class provides an empty implementation of FooParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  FooParserBaseVisitor : public FooParserVisitor {
public:

  virtual antlrcpp::Any visitInstructions(FooParser::InstructionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBody(FooParser::BodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(FooParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryNegativeExpression(FooParser::UnaryNegativeExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInParenExpression(FooParser::InParenExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryOperation(FooParser::BinaryOperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNameExpression(FooParser::NameExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteralExpression(FooParser::LiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryMultiplyOperation(FooParser::BinaryMultiplyOperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryConditionalOperation(FooParser::BinaryConditionalOperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableAffectation(FooParser::VariableAffectationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(FooParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntegerLiteral(FooParser::IntegerLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclaration(FooParser::VariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrintStatement(FooParser::PrintStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(FooParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStatement(FooParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStatement(FooParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEos(FooParser::EosContext *ctx) override {
    return visitChildren(ctx);
  }


};

