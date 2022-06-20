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
letter [a-zA-Z]

%%

"main"                                      { return MainPatternAction(yytext); }

";"                                         { return SemiColonPatternAction(yytext); }

"+"											{ return TokenIDPatternAction(yytext, ADD); }
"-"											{ return TokenIDPatternAction(yytext, SUB); }
"*"											{ return TokenIDPatternAction(yytext, MUL); }
"/"											{ return TokenIDPatternAction(yytext, DIV); }
"!"                                         { return TokenIDPatternAction(yytext, FACT); }
"**"                                        { return TokenIDPatternAction(yytext, POW); }
"sqrt"                                      { return TokenIDPatternAction(yytext, SQRT); }

"("											{ return TokenIDPatternAction(yytext, OPEN_PARENTHESIS); }
")"											{ return TokenIDPatternAction(yytext, CLOSE_PARENTHESIS); }

"{"											{ return TokenIDPatternAction(yytext, OPEN_BRACE); }
"}"											{ return TokenIDPatternAction(yytext, CLOSE_BRACE); }

"="                                         { return TokenIDPatternAction(yytext, ASSIGN); }

"=="                                        { return TokenIDPatternAction(yytext, EQ); }
"!="                                        { return TokenIDPatternAction(yytext, NE); }
"<="                                        { return TokenIDPatternAction(yytext, LE); }
">="                                        { return TokenIDPatternAction(yytext, GE); }
"<"                                         { return TokenIDPatternAction(yytext, LT); }
">"                                         { return TokenIDPatternAction(yytext, GT); }

"sumwith"                                   { return TokenIDPatternAction(yytext, SUM_WITH); } 

"if"                                        { return TokenIDPatternAction(yytext, IF); }
"else"                                      { return TokenIDPatternAction(yytext, ELSE); }

"foreach"                                   { return TokenIDPatternAction(yytext, FOREACH); }

#.*                                         { IgnoredPatternAction(yytext); }

","                                         { return TokenIDPatternAction(yytext, COMMA); }

"integer"                                   { return TokenIDPatternAction(yytext, INTEGER_TYPE); }
"float"                                     { return TokenIDPatternAction(yytext, FLOAT_TYPE); }
"string"                                    { return TokenIDPatternAction(yytext, STRING_TYPE); }
"list"                                      { return TokenIDPatternAction(yytext, LIST_TYPE); }

"binomial"                                  { return TokenIDPatternAction(yytext, BINOMIAL_DIST_TYPE); }
"normal"                                    { return TokenIDPatternAction(yytext, NORMAL_DIST_TYPE); }
"poisson"                                   { return TokenIDPatternAction(yytext, POISSON_DIST_TYPE); }

"print"                                     { return TokenIDPatternAction(yytext, PRINT); }
"input"                                     { return TokenIDPatternAction(yytext, INPUT); }

"mean"                                      { return TokenIDPatternAction(yytext, MEAN); }
"mode"                                      { return TokenIDPatternAction(yytext, MODE); }
"variance"                                  { return TokenIDPatternAction(yytext, VARIANCE); }
"kurtosis"                                  { return TokenIDPatternAction(yytext, KURTOSIS); }
"q1"                                        { return TokenIDPatternAction(yytext, Q1); }
"q3"                                        { return TokenIDPatternAction(yytext, Q3); }
"max"                                       { return TokenIDPatternAction(yytext, MAX); }
"min"                                       { return TokenIDPatternAction(yytext, MIN); }
"sd"                                        { return TokenIDPatternAction(yytext, SD); }
"skewness"                                  { return TokenIDPatternAction(yytext, SKEWNESS); }

-?(0|[1-9]{digit}*) 						{ return IntegerPatternAction(yytext); }

-?(0|[1-9]{digit}*)\.{digit}+               { return FloatPatternAction(yytext); }

\"[^\"]+\"                                  { return StringPatternAction(yytext); }

[a-zA-Z_][a-zA-Z0-9_]*                      { return VariableNamePatternAction(yytext); }

\[{whitespace}*-?(0|[1-9]{digit}*)\.{digit}*({whitespace}*,{whitespace}*-?(0|[1-9]{digit}*)\.{digit}*)*{whitespace}*\] { return ListPatternAction(yytext); }

{whitespace}								{ IgnoredPatternAction(yytext); }

.											{ return UnknownPatternAction(yytext); }

%%
