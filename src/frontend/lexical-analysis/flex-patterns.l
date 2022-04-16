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
endline			[\n]
whitespace		[ \f\n\r\t\v]

%%

"+"											{ return ADD; }
"-"											{ return SUB; }
"*"											{ return MUL; }
"/"											{ return DIV; }

"("											{ return OPEN_PARENTHESIS; }
")"											{ return CLOSE_PARENTHESIS; }

"="                                         { return AssignPatternAction(yytext); }

#.*                                         { IgnoredPatternAction(yytext); }

"integer"                                   { return IntegerTypePatternAction(yytext); }
"float"                                     { return FloatTypePatternAction(yytext); }
"string"                                    { return StringTypePatternAction(yytext); }
"list"                                      { return ListTypePatternAction(yytext); }

-?(0|[1-9]{digit}*) 						{ return IntegerPatternAction(yytext); }

-?(0|[1-9]{digit}*)\.{digit}*               { return FloatPatternAction(yytext); }

\"[^\"]+\"                                  { return StringPatternAction(yytext); }

[a-zA-Z_][a-zA-Z0-9_]*                      { return VariableNamePatternAction(yytext); }

\[{whitespace}*-?(0|[1-9]{digit}*)\.{digit}*({whitespace}*,{whitespace}*-?(0|[1-9]{digit}*)\.{digit}*)*{whitespace}*\] { return ListPatternAction(yytext); }

{endline}                                   { EndLinePatternAction(yytext); }

<<EOF>>                                     { static int findEOFF = 0; return findEOFF++ ? 0 : EOFF; }

{whitespace}								{ IgnoredPatternAction(yytext); }

.											{ return UnknownPatternAction(yytext); }

%%
