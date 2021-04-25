lexer grammar FooLexer;

// Operators
Add: '+';
Sub: '-';
Mul: '*';
Div: '/';
Mod: '%';

Equal: '=';

// Pairs
OpeningParen: '(';
ClosingParen: ')';
OpeningBrace: '{';
ClosingBrace: '}';
OpeningBracket: '[';
ClosingBracket: ']';

// Variable
VariableDeclarator: 'let';

// Print
Print: 'print';

// Statements
If: 'if';
While: 'while';

// Others
Comma: ',';

InstructionsSeparator: ';'+;

VariableName: Name;
fragment Name: [a-zA-Z_] [a-zA-Z0-9_]*;

// Literals
StringLiteral: '"' StringChar* '"';
CharLiteral: '\'' CharChar+ '\'';

fragment StringChar: ~ ["\r\n] | Escape;
fragment CharChar: ~ ['\r\n] | Escape;

DecimalLiteral: NONZERODIGIT DIGIT*;

ZeroLiteral: '0';

HexadecimalLiteral: ('0x' | '0X') HEXADECIMALDIGIT+;

BinaryLiteral: ('0b' | '0B') BINARYDIGIT+;

// Comments
Comment: '//' CommentLine* -> skip;
fragment CommentLine: ~ [\\\r\n] | Escape;

// Specials
WhiteSpace: [ \t]+ -> skip;
LineTerminator: [\r\n] -> channel(HIDDEN);

fragment Escape: '\\\'' | '\\"' | '\\\\' | '\\n' | '\\r';

fragment NONDIGIT: [a-zA-Z_];
fragment DIGIT: [0-9];
fragment NONZERODIGIT: [1-9];
fragment HEXADECIMALDIGIT: [0-9a-fA-F];
fragment BINARYDIGIT: [01];
