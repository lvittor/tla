%{

#include "bison-actions.h"

%}

// IDs de los tokens generados desde Flex:
%token ADD
%token SUB
%token MUL
%token DIV
%token FACT
%token EQ
%token NEQ
%token LEQ
%token GEQ
%token LOW
%token GTR

%token OPEN_PARENTHESIS
%token CLOSE_PARENTHESIS

%token INTEGER

// Reglas de asociatividad y precedencia (de menor a mayor):
%left ADD SUB
%left MUL DIV
%left FACT
%left EQ NEQ LEQ GEQ LOW GTR

%%

program: expression												{ $$ = ProgramGrammarAction($1); }
	;

expression: expression ADD expression							{ $$ = AdditionExpressionGrammarAction($1, $3); }
	| expression SUB expression									{ $$ = SubtractionExpressionGrammarAction($1, $3); }
	| expression MUL expression									{ $$ = MultiplicationExpressionGrammarAction($1, $3); }
	| expression DIV expression									{ $$ = DivisionExpressionGrammarAction($1, $3); }
	| expression FACT											{ $$ = FactorialExpressionGrammarAction($1); }
	| comparison												{ $$ = ComparisonGrammarAction($1); }
	| factor													{ $$ = FactorExpressionGrammarAction($1); }
	;

comparison: expression EQ expression							{ $$ = EqualComparisonGrammarAction($1, $3); }
	| expression NEQ expression									{ $$ = NotEqualComparisonGrammarAction($1, $3); }
	| expression LEQ expression									{ $$ = LowerOrEqualComparisonGrammarAction($1, $3); }
	| expression GEQ expression									{ $$ = GreaterOrEqualComparisonGrammarAction($1, $3); }
	| expression LOW expression									{ $$ = LowerComparisonGrammarAction($1, $3); }
	| expression GTR expression									{ $$ = GreaterComparisonGrammarAction($1, $3); }
	;

factor: OPEN_PARENTHESIS expression CLOSE_PARENTHESIS			{ $$ = ExpressionFactorGrammarAction($2); }
	| constant													{ $$ = ConstantFactorGrammarAction($1); }
	;

constant: INTEGER												{ $$ = IntegerConstantGrammarAction($1); }
	;

%%
