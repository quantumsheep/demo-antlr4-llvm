parser grammar FooParser;

options {
	tokenVocab = FooLexer;
}

declaration: Let Name Equal expression;

expression:
	expression Mul expression	# MultiplicationExpression
	| expression Add expression	# AdditionExpression
	| Number					# NumberLiteralExpression;
