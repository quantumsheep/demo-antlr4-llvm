lexer grammar FooLexer;

Let: 'let';

Add: '+';
Mul: '*';
Equal: '=';
Name: [a-zA-Z_][a-zA-Z0-9_]*;
Number: [1-9][0-9]*;

WhiteSpace: [ \t]+ -> skip;
LineTerminator: [\r\n] -> channel(HIDDEN);
