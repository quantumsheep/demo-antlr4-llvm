
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


//----------------- DeclarationContext ------------------------------------------------------------------

FooParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FooParser::DeclarationContext::Let() {
  return getToken(FooParser::Let, 0);
}

tree::TerminalNode* FooParser::DeclarationContext::Name() {
  return getToken(FooParser::Name, 0);
}

tree::TerminalNode* FooParser::DeclarationContext::Equal() {
  return getToken(FooParser::Equal, 0);
}

FooParser::ExpressionContext* FooParser::DeclarationContext::expression() {
  return getRuleContext<FooParser::ExpressionContext>(0);
}


size_t FooParser::DeclarationContext::getRuleIndex() const {
  return FooParser::RuleDeclaration;
}


antlrcpp::Any FooParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

FooParser::DeclarationContext* FooParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 0, FooParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(4);
    match(FooParser::Let);
    setState(5);
    match(FooParser::Name);
    setState(6);
    match(FooParser::Equal);
    setState(7);
    expression(0);
   
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

//----------------- NumberLiteralExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FooParser::NumberLiteralExpressionContext::Number() {
  return getToken(FooParser::Number, 0);
}

FooParser::NumberLiteralExpressionContext::NumberLiteralExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FooParser::NumberLiteralExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitNumberLiteralExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AdditionExpressionContext ------------------------------------------------------------------

std::vector<FooParser::ExpressionContext *> FooParser::AdditionExpressionContext::expression() {
  return getRuleContexts<FooParser::ExpressionContext>();
}

FooParser::ExpressionContext* FooParser::AdditionExpressionContext::expression(size_t i) {
  return getRuleContext<FooParser::ExpressionContext>(i);
}

tree::TerminalNode* FooParser::AdditionExpressionContext::Add() {
  return getToken(FooParser::Add, 0);
}

FooParser::AdditionExpressionContext::AdditionExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FooParser::AdditionExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitAdditionExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiplicationExpressionContext ------------------------------------------------------------------

std::vector<FooParser::ExpressionContext *> FooParser::MultiplicationExpressionContext::expression() {
  return getRuleContexts<FooParser::ExpressionContext>();
}

FooParser::ExpressionContext* FooParser::MultiplicationExpressionContext::expression(size_t i) {
  return getRuleContext<FooParser::ExpressionContext>(i);
}

tree::TerminalNode* FooParser::MultiplicationExpressionContext::Mul() {
  return getToken(FooParser::Mul, 0);
}

FooParser::MultiplicationExpressionContext::MultiplicationExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any FooParser::MultiplicationExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FooParserVisitor*>(visitor))
    return parserVisitor->visitMultiplicationExpression(this);
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
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, FooParser::RuleExpression, precedence);

    

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
    _localctx = _tracker.createInstance<NumberLiteralExpressionContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(10);
    match(FooParser::Number);
    _ctx->stop = _input->LT(-1);
    setState(20);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(18);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplicationExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(12);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(13);
          match(FooParser::Mul);
          setState(14);
          expression(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AdditionExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(15);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(16);
          match(FooParser::Add);
          setState(17);
          expression(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(22);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
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
    case 1: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool FooParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);

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
  "declaration", "expression"
};

std::vector<std::string> FooParser::_literalNames = {
  "", "'let'", "'+'", "'*'", "'='"
};

std::vector<std::string> FooParser::_symbolicNames = {
  "", "Let", "Add", "Mul", "Equal", "Name", "Number", "WhiteSpace", "LineTerminator"
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
    0x3, 0xa, 0x1a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x15, 
    0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x18, 0xb, 0x3, 0x3, 0x3, 0x2, 0x3, 0x4, 
    0x4, 0x2, 0x4, 0x2, 0x2, 0x2, 0x19, 0x2, 0x6, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0x6, 0x7, 0x7, 0x3, 0x2, 0x2, 0x7, 0x8, 0x7, 
    0x7, 0x2, 0x2, 0x8, 0x9, 0x7, 0x6, 0x2, 0x2, 0x9, 0xa, 0x5, 0x4, 0x3, 
    0x2, 0xa, 0x3, 0x3, 0x2, 0x2, 0x2, 0xb, 0xc, 0x8, 0x3, 0x1, 0x2, 0xc, 
    0xd, 0x7, 0x8, 0x2, 0x2, 0xd, 0x16, 0x3, 0x2, 0x2, 0x2, 0xe, 0xf, 0xc, 
    0x5, 0x2, 0x2, 0xf, 0x10, 0x7, 0x5, 0x2, 0x2, 0x10, 0x15, 0x5, 0x4, 
    0x3, 0x6, 0x11, 0x12, 0xc, 0x4, 0x2, 0x2, 0x12, 0x13, 0x7, 0x4, 0x2, 
    0x2, 0x13, 0x15, 0x5, 0x4, 0x3, 0x5, 0x14, 0xe, 0x3, 0x2, 0x2, 0x2, 
    0x14, 0x11, 0x3, 0x2, 0x2, 0x2, 0x15, 0x18, 0x3, 0x2, 0x2, 0x2, 0x16, 
    0x14, 0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 0x3, 0x2, 0x2, 0x2, 0x17, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0x16, 0x3, 0x2, 0x2, 0x2, 0x4, 0x14, 0x16, 
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
