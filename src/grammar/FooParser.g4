parser grammar FooParser;

options {
	tokenVocab = FooLexer;
}

instructions: statement* eos;

statement:
	expression InstructionsSeparator
	| variableDeclaration InstructionsSeparator
	| printStatement InstructionsSeparator;

expression:
	'(' expression ')'							# InParenExpression
	| '-' expression							# UnaryNegativeExpression
	| VariableName								# NameExpression
	| expression (Mul | Div | Mod) expression	# BinaryMultiplyOperation
	| expression (Add | Sub) expression			# BinaryOperation
	| literal									# LiteralExpression;

literal: integerLiteral;

integerLiteral:
	(
		DecimalLiteral
		| ZeroLiteral
		| HexadecimalLiteral
		| BinaryLiteral
	);

variableDeclaration:
	VariableDeclarator VariableName '=' expression;

printStatement: Print '(' expression (',' expression)* ')';

type: VariableName;

eos: (EOF | LineTerminator);
