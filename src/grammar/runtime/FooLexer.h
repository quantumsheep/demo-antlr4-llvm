
// Generated from /Users/qtmsheep/Development/dev-day-language/src/grammar/FooLexer.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  FooLexer : public antlr4::Lexer {
public:
  enum {
    Add = 1, Sub = 2, Mul = 3, Div = 4, Mod = 5, Gt = 6, Gte = 7, Lt = 8, 
    Lte = 9, Eq = 10, Ne = 11, Equal = 12, OpeningParen = 13, ClosingParen = 14, 
    OpeningBrace = 15, ClosingBrace = 16, OpeningBracket = 17, ClosingBracket = 18, 
    VariableDeclarator = 19, Print = 20, If = 21, While = 22, Comma = 23, 
    InstructionsSeparator = 24, VariableName = 25, StringLiteral = 26, CharLiteral = 27, 
    DecimalLiteral = 28, ZeroLiteral = 29, HexadecimalLiteral = 30, BinaryLiteral = 31, 
    Comment = 32, WhiteSpace = 33, LineTerminator = 34
  };

  explicit FooLexer(antlr4::CharStream *input);
  ~FooLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

