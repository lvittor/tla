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
"!"                                         { return FACT; }
"**"                                        { return POW; }
"sqrt"                                      { return SQRT; }

"("											{ return OPEN_PARENTHESIS; }
")"											{ return CLOSE_PARENTHESIS; }

"{"											{ return OpenBracePatternAction(yytext); }
"}"											{ return CloseBracePatternAction(yytext); }

"="                                         { return AssignPatternAction(yytext); }

"=="                                        { return EQ; }
"!="                                        { return NE; }
"<="                                        { return LE; }
">="                                        { return GE; }
"<"                                         { return LT; }
">"                                         { return GT; }

"sum with"                                  { return SumWithPatternAction(yytext); } 

"if"                                        { return IfPatternAction(yytext); }
"else"                                      { return ElsePatternAction(yytext); }

"foreach"                                   { return ForeachPatternAction(yytext);}

#.*                                         { IgnoredPatternAction(yytext); }

","                                         { return CommaPatternAction(yytext); }

"integer"                                   { return IntegerTypePatternAction(yytext); }
"float"                                     { return FloatTypePatternAction(yytext); }
"string"                                    { return StringTypePatternAction(yytext); }
"list"                                      { return ListTypePatternAction(yytext); }

"binomial"                                  { return BinomialTypePatternAction(yytext); }
"normal"                                    { return NormalTypePatternAction(yytext); }
"poisson"                                   { return PoissonTypePatternAction(yytext); }

"print"                                     { return PrintPatternAction(yytext); }
"input"                                     { return InputPatternAction(yytext); }

"mean"                                      { return MEAN; }
"mode"                                      { return MODE; }
"variance"                                  { return VARIANCE; }
"kurtosis"                                  { return KURTOSIS; }
"q1"                                        { return Q1; }
"q3"                                        { return Q3; }
"max"                                       { return MAX; }
"min"                                       { return MIN; }
"sd"                                        { return SD; }
"skewness"                                  { return SKEWNESS; }

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
