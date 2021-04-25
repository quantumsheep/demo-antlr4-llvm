
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
    virtual antlrcpp::Any visitInstructions(FooParser::InstructionsContext *context) = 0;

    virtual antlrcpp::Any visitBody(FooParser::BodyContext *context) = 0;

    virtual antlrcpp::Any visitStatement(FooParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitUnaryNegativeExpression(FooParser::UnaryNegativeExpressionContext *context) = 0;

    virtual antlrcpp::Any visitInParenExpression(FooParser::InParenExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBinaryOperation(FooParser::BinaryOperationContext *context) = 0;

    virtual antlrcpp::Any visitNameExpression(FooParser::NameExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLiteralExpression(FooParser::LiteralExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBinaryMultiplyOperation(FooParser::BinaryMultiplyOperationContext *context) = 0;

    virtual antlrcpp::Any visitVariableAffectation(FooParser::VariableAffectationContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(FooParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitIntegerLiteral(FooParser::IntegerLiteralContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclaration(FooParser::VariableDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitPrintStatement(FooParser::PrintStatementContext *context) = 0;

    virtual antlrcpp::Any visitType(FooParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitIfStatement(FooParser::IfStatementContext *context) = 0;

    virtual antlrcpp::Any visitEos(FooParser::EosContext *context) = 0;


};

