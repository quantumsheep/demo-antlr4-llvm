
// Generated from /Users/qtmsheep/Development/dev-day-language/src/grammar/FooParser.g4 by ANTLR 4.9.1


#include "FooParserVisitor.h"

#include "FooParser.h"


using namespace antlrcpp;
using namespace antlr4;

FooParser::FooParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

FooParser::~FooParser() {
  delete _interpreter;
}

std::string FooParser::getGrammarFileName() const {
  return "FooParser.g4";
}

const std::vector<std::string>& FooParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& FooParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- InstructionsContext ------------------------------------------------------------------

FooParser::InstructionsContext::InstructionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FooParser::EosContext* FooParser::InstructionsContext::eos() {
  return getRuleContext<FooParser::EosContext>(0);
}

std::vector<FooParser::StatementContext *> FooParser::InstructionsContext::statement() {
  return getRuleContexts<FooParser::StatementContext>();
}

FooParser::StatementContext* FooParser::InstructionsContext::statement(size_t i) {
  return getRuleContext<FooParser::StatementContext>(i);
}


size_t FooParser::InstructionsContext::getRuleIndex() const {
  return FooParser::RuleInstructions;
}


antlrcpp::Any FooParser::InstructionsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitInstructions(this);
  else
    return visitor->visitChildren(this);
}

FooParser::InstructionsContext* FooParser::instructions() {
  InstructionsContext *_localctx = _tracker.createInstance<InstructionsContext>(_ctx, getState());
  enterRule(_localctx, 0, FooParser::RuleInstructions);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(21);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FooParser::Sub)
      | (1ULL << FooParser::OpeningParen)
      | (1ULL << FooParser::VariableDeclarator)
      | (1ULL << FooParser::Print)
      | (1ULL << FooParser::VariableName)
      | (1ULL << FooParser::DecimalLiteral)
      | (1ULL << FooParser::ZeroLiteral)
      | (1ULL << FooParser::HexadecimalLiteral)
      | (1ULL << FooParser::BinaryLiteral))) != 0)) {
      setState(18);
      statement();
      setState(23);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(24);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

FooParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FooParser::VariableDeclarationContext* FooParser::StatementContext::variableDeclaration() {
  return getRuleContext<FooParser::VariableDeclarationContext>(0);
}

tree::TerminalNode* FooParser::StatementContext::InstructionsSeparator() {
  return getToken(FooParser::InstructionsSeparator, 0);
}

FooParser::PrintStatementContext* FooParser::StatementContext::printStatement() {
  return getRuleContext<FooParser::PrintStatementContext>(0);
}

FooParser::ExpressionContext* FooParser::StatementContext::expression() {
  return getRuleContext<FooParser::ExpressionContext>(0);
}


size_t FooParser::StatementContext::getRuleIndex() const {
  return FooParser::RuleStatement;
}


antlrcpp::Any FooParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

FooParser::StatementContext* FooParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, FooParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(35);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FooParser::VariableDeclarator: {
        enterOuterAlt(_localctx, 1);
        setState(26);
        variableDeclaration();
        setState(27);
        match(FooParser::InstructionsSeparator);
        break;
      }

      case FooParser::Print: {
        enterOuterAlt(_localctx, 2);
        setState(29);
        printStatement();
        setState(30);
        match(FooParser::InstructionsSeparator);
        break;
      }

      case FooParser::Sub:
      case FooParser::OpeningParen:
      case FooParser::VariableName:
      case FooParser::DecimalLiteral:
      case FooParser::ZeroLiteral:
      case FooParser::HexadecimalLiteral:
      case FooParser::BinaryLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(32);
        expression(0);
        setState(33);
        match(FooParser::InstructionsSeparator);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

FooParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FooParser::ExpressionContext::getRuleIndex() const {
  return FooParser::RuleExpression;
}

void FooParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnaryNegativeExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FooParser::UnaryNegativeExpressionContext::Sub() {
  return getToken(FooParser::Sub, 0);
}

FooParser::ExpressionContext* FooParser::UnaryNegativeExpressionContext::expression() {
  return getRuleContext<FooParser::ExpressionContext>(0);
}

FooParser::UnaryNegativeExpressionContext::UnaryNegativeExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FooParser::UnaryNegativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitUnaryNegativeExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InParenExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FooParser::InParenExpressionContext::OpeningParen() {
  return getToken(FooParser::OpeningParen, 0);
}

FooParser::ExpressionContext* FooParser::InParenExpressionContext::expression() {
  return getRuleContext<FooParser::ExpressionContext>(0);
}

tree::TerminalNode* FooParser::InParenExpressionContext::ClosingParen() {
  return getToken(FooParser::ClosingParen, 0);
}

FooParser::InParenExpressionContext::InParenExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FooParser::InParenExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitInParenExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryOperationContext ------------------------------------------------------------------

std::vector<FooParser::ExpressionContext *> FooParser::BinaryOperationContext::expression() {
  return getRuleContexts<FooParser::ExpressionContext>();
}

FooParser::ExpressionContext* FooParser::BinaryOperationContext::expression(size_t i) {
  return getRuleContext<FooParser::ExpressionContext>(i);
}

tree::TerminalNode* FooParser::BinaryOperationContext::Add() {
  return getToken(FooParser::Add, 0);
}

tree::TerminalNode* FooParser::BinaryOperationContext::Sub() {
  return getToken(FooParser::Sub, 0);
}

FooParser::BinaryOperationContext::BinaryOperationContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FooParser::BinaryOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitBinaryOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NameExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FooParser::NameExpressionContext::VariableName() {
  return getToken(FooParser::VariableName, 0);
}

FooParser::NameExpressionContext::NameExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FooParser::NameExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitNameExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralExpressionContext ------------------------------------------------------------------

FooParser::LiteralContext* FooParser::LiteralExpressionContext::literal() {
  return getRuleContext<FooParser::LiteralContext>(0);
}

FooParser::LiteralExpressionContext::LiteralExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FooParser::LiteralExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitLiteralExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryMultiplyOperationContext ------------------------------------------------------------------

std::vector<FooParser::ExpressionContext *> FooParser::BinaryMultiplyOperationContext::expression() {
  return getRuleContexts<FooParser::ExpressionContext>();
}

FooParser::ExpressionContext* FooParser::BinaryMultiplyOperationContext::expression(size_t i) {
  return getRuleContext<FooParser::ExpressionContext>(i);
}

tree::TerminalNode* FooParser::BinaryMultiplyOperationContext::Mul() {
  return getToken(FooParser::Mul, 0);
}

tree::TerminalNode* FooParser::BinaryMultiplyOperationContext::Div() {
  return getToken(FooParser::Div, 0);
}

tree::TerminalNode* FooParser::BinaryMultiplyOperationContext::Mod() {
  return getToken(FooParser::Mod, 0);
}

FooParser::BinaryMultiplyOperationContext::BinaryMultiplyOperationContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FooParser::BinaryMultiplyOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitBinaryMultiplyOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableAffectationContext ------------------------------------------------------------------

tree::TerminalNode* FooParser::VariableAffectationContext::VariableName() {
  return getToken(FooParser::VariableName, 0);
}

tree::TerminalNode* FooParser::VariableAffectationContext::Equal() {
  return getToken(FooParser::Equal, 0);
}

FooParser::ExpressionContext* FooParser::VariableAffectationContext::expression() {
  return getRuleContext<FooParser::ExpressionContext>(0);
}

FooParser::VariableAffectationContext::VariableAffectationContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FooParser::VariableAffectationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitVariableAffectation(this);
  else
    return visitor->visitChildren(this);
}

FooParser::ExpressionContext* FooParser::expression() {
   return expression(0);
}

FooParser::ExpressionContext* FooParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FooParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  FooParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, FooParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(49);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<InParenExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(38);
      match(FooParser::OpeningParen);
      setState(39);
      expression(0);
      setState(40);
      match(FooParser::ClosingParen);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UnaryNegativeExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(42);
      match(FooParser::Sub);
      setState(43);
      expression(6);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<NameExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(44);
      match(FooParser::VariableName);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<VariableAffectationContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(45);
      match(FooParser::VariableName);
      setState(46);
      match(FooParser::Equal);
      setState(47);
      expression(2);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<LiteralExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(48);
      literal();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(59);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(57);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryMultiplyOperationContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(51);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(52);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << FooParser::Mul)
            | (1ULL << FooParser::Div)
            | (1ULL << FooParser::Mod))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(53);
          expression(5);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(54);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(55);
          _la = _input->LA(1);
          if (!(_la == FooParser::Add

          || _la == FooParser::Sub)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(56);
          expression(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(61);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

FooParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FooParser::IntegerLiteralContext* FooParser::LiteralContext::integerLiteral() {
  return getRuleContext<FooParser::IntegerLiteralContext>(0);
}


size_t FooParser::LiteralContext::getRuleIndex() const {
  return FooParser::RuleLiteral;
}


antlrcpp::Any FooParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

FooParser::LiteralContext* FooParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 6, FooParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(62);
    integerLiteral();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegerLiteralContext ------------------------------------------------------------------

FooParser::IntegerLiteralContext::IntegerLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FooParser::IntegerLiteralContext::DecimalLiteral() {
  return getToken(FooParser::DecimalLiteral, 0);
}

tree::TerminalNode* FooParser::IntegerLiteralContext::ZeroLiteral() {
  return getToken(FooParser::ZeroLiteral, 0);
}

tree::TerminalNode* FooParser::IntegerLiteralContext::HexadecimalLiteral() {
  return getToken(FooParser::HexadecimalLiteral, 0);
}

tree::TerminalNode* FooParser::IntegerLiteralContext::BinaryLiteral() {
  return getToken(FooParser::BinaryLiteral, 0);
}


size_t FooParser::IntegerLiteralContext::getRuleIndex() const {
  return FooParser::RuleIntegerLiteral;
}


antlrcpp::Any FooParser::IntegerLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitIntegerLiteral(this);
  else
    return visitor->visitChildren(this);
}

FooParser::IntegerLiteralContext* FooParser::integerLiteral() {
  IntegerLiteralContext *_localctx = _tracker.createInstance<IntegerLiteralContext>(_ctx, getState());
  enterRule(_localctx, 8, FooParser::RuleIntegerLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FooParser::DecimalLiteral)
      | (1ULL << FooParser::ZeroLiteral)
      | (1ULL << FooParser::HexadecimalLiteral)
      | (1ULL << FooParser::BinaryLiteral))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

FooParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FooParser::VariableDeclarationContext::VariableDeclarator() {
  return getToken(FooParser::VariableDeclarator, 0);
}

tree::TerminalNode* FooParser::VariableDeclarationContext::VariableName() {
  return getToken(FooParser::VariableName, 0);
}

tree::TerminalNode* FooParser::VariableDeclarationContext::Equal() {
  return getToken(FooParser::Equal, 0);
}

FooParser::ExpressionContext* FooParser::VariableDeclarationContext::expression() {
  return getRuleContext<FooParser::ExpressionContext>(0);
}


size_t FooParser::VariableDeclarationContext::getRuleIndex() const {
  return FooParser::RuleVariableDeclaration;
}


antlrcpp::Any FooParser::VariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}

FooParser::VariableDeclarationContext* FooParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 10, FooParser::RuleVariableDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(FooParser::VariableDeclarator);
    setState(67);
    match(FooParser::VariableName);
    setState(68);
    match(FooParser::Equal);
    setState(69);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintStatementContext ------------------------------------------------------------------

FooParser::PrintStatementContext::PrintStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FooParser::PrintStatementContext::Print() {
  return getToken(FooParser::Print, 0);
}

tree::TerminalNode* FooParser::PrintStatementContext::OpeningParen() {
  return getToken(FooParser::OpeningParen, 0);
}

std::vector<FooParser::ExpressionContext *> FooParser::PrintStatementContext::expression() {
  return getRuleContexts<FooParser::ExpressionContext>();
}

FooParser::ExpressionContext* FooParser::PrintStatementContext::expression(size_t i) {
  return getRuleContext<FooParser::ExpressionContext>(i);
}

tree::TerminalNode* FooParser::PrintStatementContext::ClosingParen() {
  return getToken(FooParser::ClosingParen, 0);
}

std::vector<tree::TerminalNode *> FooParser::PrintStatementContext::Comma() {
  return getTokens(FooParser::Comma);
}

tree::TerminalNode* FooParser::PrintStatementContext::Comma(size_t i) {
  return getToken(FooParser::Comma, i);
}


size_t FooParser::PrintStatementContext::getRuleIndex() const {
  return FooParser::RulePrintStatement;
}


antlrcpp::Any FooParser::PrintStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitPrintStatement(this);
  else
    return visitor->visitChildren(this);
}

FooParser::PrintStatementContext* FooParser::printStatement() {
  PrintStatementContext *_localctx = _tracker.createInstance<PrintStatementContext>(_ctx, getState());
  enterRule(_localctx, 12, FooParser::RulePrintStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    match(FooParser::Print);
    setState(72);
    match(FooParser::OpeningParen);
    setState(73);
    expression(0);
    setState(78);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FooParser::Comma) {
      setState(74);
      match(FooParser::Comma);
      setState(75);
      expression(0);
      setState(80);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(81);
    match(FooParser::ClosingParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

FooParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FooParser::TypeContext::VariableName() {
  return getToken(FooParser::VariableName, 0);
}


size_t FooParser::TypeContext::getRuleIndex() const {
  return FooParser::RuleType;
}


antlrcpp::Any FooParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

FooParser::TypeContext* FooParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 14, FooParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    match(FooParser::VariableName);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EosContext ------------------------------------------------------------------

FooParser::EosContext::EosContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FooParser::EosContext::EOF() {
  return getToken(FooParser::EOF, 0);
}

tree::TerminalNode* FooParser::EosContext::LineTerminator() {
  return getToken(FooParser::LineTerminator, 0);
}


size_t FooParser::EosContext::getRuleIndex() const {
  return FooParser::RuleEos;
}


antlrcpp::Any FooParser::EosContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitEos(this);
  else
    return visitor->visitChildren(this);
}

FooParser::EosContext* FooParser::eos() {
  EosContext *_localctx = _tracker.createInstance<EosContext>(_ctx, getState());
  enterRule(_localctx, 16, FooParser::RuleEos);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    _la = _input->LA(1);
    if (!(_la == FooParser::EOF

    || _la == FooParser::LineTerminator)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool FooParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool FooParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> FooParser::_decisionToDFA;
atn::PredictionContextCache FooParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN FooParser::_atn;
std::vector<uint16_t> FooParser::_serializedATN;

std::vector<std::string> FooParser::_ruleNames = {
  "instructions", "statement", "expression", "literal", "integerLiteral", 
  "variableDeclaration", "printStatement", "type", "eos"
};

std::vector<std::string> FooParser::_literalNames = {
  "", "'+'", "'-'", "'*'", "'/'", "'%'", "'='", "'('", "')'", "'{'", "'}'", 
  "'['", "']'", "'let'", "'print'", "','", "", "", "", "", "", "'0'"
};

std::vector<std::string> FooParser::_symbolicNames = {
  "", "Add", "Sub", "Mul", "Div", "Mod", "Equal", "OpeningParen", "ClosingParen", 
  "OpeningBrace", "ClosingBrace", "OpeningBracket", "ClosingBracket", "VariableDeclarator", 
  "Print", "Comma", "InstructionsSeparator", "VariableName", "StringLiteral", 
  "CharLiteral", "DecimalLiteral", "ZeroLiteral", "HexadecimalLiteral", 
  "BinaryLiteral", "Comment", "WhiteSpace", "LineTerminator"
};

dfa::Vocabulary FooParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> FooParser::_tokenNames;

FooParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x1c, 0x5a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x3, 0x2, 0x7, 
    0x2, 0x16, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x19, 0xb, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x26, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x34, 0xa, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x3c, 0xa, 0x4, 
    0xc, 0x4, 0xe, 0x4, 0x3f, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x4f, 0xa, 0x8, 0xc, 0x8, 
    0xe, 0x8, 0x52, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x2, 0x3, 0x6, 0xb, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x2, 0x6, 0x3, 0x2, 0x5, 0x7, 0x3, 0x2, 0x3, 0x4, 
    0x3, 0x2, 0x16, 0x19, 0x3, 0x3, 0x1c, 0x1c, 0x2, 0x5a, 0x2, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x25, 0x3, 0x2, 0x2, 0x2, 0x6, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x40, 0x3, 0x2, 0x2, 0x2, 0xa, 0x42, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x44, 0x3, 0x2, 0x2, 0x2, 0xe, 0x49, 0x3, 0x2, 0x2, 0x2, 0x10, 0x55, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0x57, 0x3, 0x2, 0x2, 0x2, 0x14, 0x16, 0x5, 
    0x4, 0x3, 0x2, 0x15, 0x14, 0x3, 0x2, 0x2, 0x2, 0x16, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x17, 0x15, 0x3, 0x2, 0x2, 0x2, 0x17, 0x18, 0x3, 0x2, 0x2, 
    0x2, 0x18, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x19, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x1a, 0x1b, 0x5, 0x12, 0xa, 0x2, 0x1b, 0x3, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0x1d, 0x5, 0xc, 0x7, 0x2, 0x1d, 0x1e, 0x7, 0x12, 0x2, 0x2, 0x1e, 0x26, 
    0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x5, 0xe, 0x8, 0x2, 0x20, 0x21, 0x7, 
    0x12, 0x2, 0x2, 0x21, 0x26, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x5, 0x6, 
    0x4, 0x2, 0x23, 0x24, 0x7, 0x12, 0x2, 0x2, 0x24, 0x26, 0x3, 0x2, 0x2, 
    0x2, 0x25, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x25, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0x25, 0x22, 0x3, 0x2, 0x2, 0x2, 0x26, 0x5, 0x3, 0x2, 0x2, 0x2, 0x27, 
    0x28, 0x8, 0x4, 0x1, 0x2, 0x28, 0x29, 0x7, 0x9, 0x2, 0x2, 0x29, 0x2a, 
    0x5, 0x6, 0x4, 0x2, 0x2a, 0x2b, 0x7, 0xa, 0x2, 0x2, 0x2b, 0x34, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x4, 0x2, 0x2, 0x2d, 0x34, 0x5, 0x6, 
    0x4, 0x8, 0x2e, 0x34, 0x7, 0x13, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x13, 0x2, 
    0x2, 0x30, 0x31, 0x7, 0x8, 0x2, 0x2, 0x31, 0x34, 0x5, 0x6, 0x4, 0x4, 
    0x32, 0x34, 0x5, 0x8, 0x5, 0x2, 0x33, 0x27, 0x3, 0x2, 0x2, 0x2, 0x33, 
    0x2c, 0x3, 0x2, 0x2, 0x2, 0x33, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x33, 0x2f, 
    0x3, 0x2, 0x2, 0x2, 0x33, 0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 0x3d, 0x3, 
    0x2, 0x2, 0x2, 0x35, 0x36, 0xc, 0x6, 0x2, 0x2, 0x36, 0x37, 0x9, 0x2, 
    0x2, 0x2, 0x37, 0x3c, 0x5, 0x6, 0x4, 0x7, 0x38, 0x39, 0xc, 0x5, 0x2, 
    0x2, 0x39, 0x3a, 0x9, 0x3, 0x2, 0x2, 0x3a, 0x3c, 0x5, 0x6, 0x4, 0x6, 
    0x3b, 0x35, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x3f, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 
    0x3, 0x2, 0x2, 0x2, 0x3e, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3d, 0x3, 
    0x2, 0x2, 0x2, 0x40, 0x41, 0x5, 0xa, 0x6, 0x2, 0x41, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x43, 0x9, 0x4, 0x2, 0x2, 0x43, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x44, 0x45, 0x7, 0xf, 0x2, 0x2, 0x45, 0x46, 0x7, 0x13, 0x2, 0x2, 
    0x46, 0x47, 0x7, 0x8, 0x2, 0x2, 0x47, 0x48, 0x5, 0x6, 0x4, 0x2, 0x48, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x7, 0x10, 0x2, 0x2, 0x4a, 0x4b, 
    0x7, 0x9, 0x2, 0x2, 0x4b, 0x50, 0x5, 0x6, 0x4, 0x2, 0x4c, 0x4d, 0x7, 
    0x11, 0x2, 0x2, 0x4d, 0x4f, 0x5, 0x6, 0x4, 0x2, 0x4e, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0x4f, 0x52, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4e, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x51, 0x3, 0x2, 0x2, 0x2, 0x51, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0xa, 0x2, 0x2, 0x54, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x7, 0x13, 0x2, 0x2, 0x56, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x9, 0x5, 0x2, 0x2, 0x58, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0x8, 0x17, 0x25, 0x33, 0x3b, 0x3d, 0x50, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

FooParser::Initializer FooParser::_init;
