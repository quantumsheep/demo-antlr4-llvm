
// Generated from /Users/qtmsheep/Development/dev-day-language/src/grammar/FooParser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "FooParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by FooParser.
 */
class  FooParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by FooParser.
   */
    virtual antlrcpp::Any visitDeclaration(FooParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitNumberLiteralExpression(FooParser::NumberLiteralExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAdditionExpression(FooParser::AdditionExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicationExpression(FooParser::MultiplicationExpressionContext *context) = 0;


};

