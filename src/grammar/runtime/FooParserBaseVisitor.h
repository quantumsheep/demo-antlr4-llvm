
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

  virtual antlrcpp::Any visitDeclaration(FooParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberLiteralExpression(FooParser::NumberLiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditionExpression(FooParser::AdditionExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplicationExpression(FooParser::MultiplicationExpressionContext *ctx) override {
    return visitChildren(ctx);
  }


};

