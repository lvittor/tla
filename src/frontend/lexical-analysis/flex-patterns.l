%{

#include "flex-actions.h"

%}

/* Obliga a crear una regla explícita para manejar lexemas desconocidos. */
%option nodefault

/* Escanea un único archivo y se detiene. */
%option noyywrap

/* Dispone una variable global "yylineno" con el número de línea actual. */
%option yylineno

/* Patrones reutilizables. */
crlf			\r\n
digit			[0-9]
endline			\n
whitespace		[ \f\n\r\t\v]

%%

"+"											{ return ADD; }
"-"											{ return SUB; }
"*"											{ return MUL; }
"/"											{ return DIV; }

"("											{ return OPEN_PARENTHESIS; }
")"											{ return CLOSE_PARENTHESIS; }

"="                                         { return ASSIGN; }

"integer"                                   { return INTEGER_TYPE; }
"float"                                     { return FLOAT_TYPE; }
"string"                                    { return STRING_TYPE; }
"list"                                      { return LIST_TYPE; }

-?{digit}+ 									{ return IntegerPatternAction(yytext); }

-?{digit}+(.{digit}+)?                      { return FloatPatternAction(yytext); }

[a-zA-Z_][a-zA-Z0-9_]*                      { return VARIABLE_NAME; }

{whitespace}								{ IgnoredPatternAction(yytext); }

.											{ return UnknownPatternAction(yytext); }

%%
