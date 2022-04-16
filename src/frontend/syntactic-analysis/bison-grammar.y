%{

#include "bison-actions.h"

%}

// IDs de los tokens generados desde Flex:
%token ADD
%token SUB
%token MUL
%token DIV
%token FACT

%token OPEN_PARENTHESIS
%token CLOSE_PARENTHESIS

%token ASSIGN

%token COMMA

%token INTEGER_TYPE FLOAT_TYPE STRING_TYPE LIST_TYPE

%token BINOMIAL_DIST_TYPE NORMAL_DIST_TYPE POISSON_DIST_TYPE

%token INTEGER FLOAT STRING LIST

%token VARIABLE_NAME

%token EOL EOFF

// Reglas de asociatividad y precedencia (de menor a mayor):
%left ADD SUB
%left MUL DIV
%left FACT

%%

program: expression program 									{ $$ = ProgramGrammarAction($1); } 
	|    EOL program											{ $$ = $2; }
	|	 EOFF													{ printf("Result: %d", $1); }
	;

expression: expression ADD expression							{ $$ = AdditionExpressionGrammarAction($1, $3); }
	| expression SUB expression									{ $$ = SubtractionExpressionGrammarAction($1, $3); }
	| expression MUL expression									{ $$ = MultiplicationExpressionGrammarAction($1, $3); }
	| expression DIV expression									{ $$ = DivisionExpressionGrammarAction($1, $3); }
	| expression FACT											{ $$ = FactorialExpressionGrammarAction($1); }
	| factor													{ $$ = FactorExpressionGrammarAction($1); }
	| declare													{ $$ = $1; }
	;

declare: type VARIABLE_NAME ASSIGN value	   					{ $$ = DeclareVariableGrammarAction($1, $2, $4); }
	| dist_declare												{ printf("Result: %d", $1); } 
	;

type: INTEGER_TYPE 												
	| FLOAT_TYPE 												
	| STRING_TYPE 												
	| LIST_TYPE													
	;

dist_declare: dist_type VARIABLE_NAME
	;

dist_type: binomial_type
	| normal_type
	| poisson_type
	;

binomial_type:  BINOMIAL_DIST_TYPE OPEN_PARENTHESIS INTEGER COMMA FLOAT CLOSE_PARENTHESIS

normal_type: NORMAL_DIST_TYPE OPEN_PARENTHESIS FLOAT COMMA FLOAT CLOSE_PARENTHESIS

poisson_type: POISSON_DIST_TYPE OPEN_PARENTHESIS INTEGER CLOSE_PARENTHESIS

value: expression												{ $$ = $1; }
	| VARIABLE_NAME												{ $$ = AddVariableReferenceGrammarAction($1); }
	;

factor: OPEN_PARENTHESIS expression CLOSE_PARENTHESIS			{ $$ = ExpressionFactorGrammarAction($2); }
	| constant													{ $$ = ConstantFactorGrammarAction($1); }
	;

constant: INTEGER												{ $$ = IntegerConstantGrammarAction($1); }
	| FLOAT														{ $$ = FloatConstantGrammarAction($1); }
	| STRING													{ $$ = StringConstantGrammarAction($1); }
	| LIST														{ $$ = ListConstantGrammarAction($1); }
	;

%%
