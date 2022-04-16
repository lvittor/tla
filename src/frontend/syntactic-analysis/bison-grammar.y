%{

#include "bison-actions.h"

%}

// IDs de los tokens generados desde Flex:
%token ADD
%token SUB
%token MUL
%token DIV

%token OPEN_PARENTHESIS
%token CLOSE_PARENTHESIS

%token ASSIGN

%token INTEGER_TYPE 
%token FLOAT_TYPE
%token STRING_TYPE
%token LIST_TYPE

%token INTEGER
%token FLOAT
%token LIST

%token VARIABLE_NAME

// Reglas de asociatividad y precedencia (de menor a mayor):
%left ADD SUB
%left MUL DIV

%%

program: expression												{ $$ = ProgramGrammarAction($1); }
	;

expression: expression ADD expression							{ $$ = AdditionExpressionGrammarAction($1, $3); }
	| expression SUB expression									{ $$ = SubtractionExpressionGrammarAction($1, $3); }
	| expression MUL expression									{ $$ = MultiplicationExpressionGrammarAction($1, $3); }
	| expression DIV expression									{ $$ = DivisionExpressionGrammarAction($1, $3); }
	| factor													{ $$ = FactorExpressionGrammarAction($1); }
	;

factor: OPEN_PARENTHESIS expression CLOSE_PARENTHESIS			{ $$ = ExpressionFactorGrammarAction($2); }
	| constant													{ $$ = ConstantFactorGrammarAction($1); }
	;

constant: INTEGER												{ $$ = IntegerConstantGrammarAction($1); }
	| FLOAT														{ $$ = FloatConstantGrammarAction($1); }
	| LIST														{ $$ = ListConstantGrammarAction($1); }
	;

type: INTEGER_TYPE 												{ ; }
	| FLOAT_TYPE 												{ ; }
	| STRING_TYPE 												{ ; }
	| LIST_TYPE													{ ; }
	;

declare: type VARIABLE_NAME ASSIGN value						{ $$ = DeclareVariableGrammarAction($1, $2, $4); }
	;

value: expression												{ $$ = $1; }
	| VARIABLE_NAME												{ $$ = AddVariableReferenceGrammarAction($1); }

%%
