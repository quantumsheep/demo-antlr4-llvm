parser grammar FooParser;

options {
	tokenVocab = FooLexer;
}

instructions: statement* eos;

body: '{' statement* '}';

statement:
	variableDeclaration InstructionsSeparator
	| body
	| ifStatement
	| printStatement InstructionsSeparator
	| expression InstructionsSeparator;

expression:
	'(' expression ')'								# InParenExpression
	| '-' expression								# UnaryNegativeExpression
	| VariableName									# NameExpression
	| expression (Mul | Div | Mod) expression		# BinaryMultiplyOperation
	| expression (Add | Sub) expression				# BinaryOperation
	| <assoc = right> VariableName '=' expression	# VariableAffectation
	| literal										# LiteralExpression;

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

ifStatement: 'if' expression body;

eos: (EOF | LineTerminator);
