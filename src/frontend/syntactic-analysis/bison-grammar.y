%{

#include "bison-actions.h"

%}

// IDs de los tokens generados desde Flex:
%token ADD
%token SUB
%token MUL
%token DIV
%token FACT
%token POW
%token SQRT

%token OPEN_PARENTHESIS CLOSE_PARENTHESIS

%token OPEN_BRACE CLOSE_BRACE

%token ASSIGN

%token EQ NE LE GE LT GT

%token SUM_WITH

%token IF ELSE

%token FOREACH

%token COMMA

%token INTEGER_TYPE FLOAT_TYPE STRING_TYPE LIST_TYPE

%token BINOMIAL_DIST_TYPE NORMAL_DIST_TYPE POISSON_DIST_TYPE

%token PRINT INPUT

%token MEAN MODE VARIANCE KURTOSIS Q1 Q3 MAX MIN SD SKEWNESS

%token INTEGER FLOAT STRING LIST

%token VARIABLE_NAME

%token EOL EOFF

// Reglas de asociatividad y precedencia (de menor a mayor):
%left ADD SUB
%left MUL DIV
%left FACT

%%

program: instruction program 									{ $$ = ProgramGrammarAction($1); } 
	|    EOL program											{ $$ = $2; }
	|	 EOFF													{ GenericLogger("EOFFProgramGrammarAction"); }
	;

instruction: declare											{ GenericLogger("DeclareInstructionGrammarAction"); }
	| print														{ GenericLogger("PrintInstructionGrammarAction"); }
	| if														{ GenericLogger("IfInstructionGrammarAction"); }
	| foreach													{ GenericLogger("ForeachGrammarAction"); }
	;

expression: expression ADD expression							{ $$ = AdditionExpressionGrammarAction($1, $3); }
	| expression SUB expression									{ $$ = SubtractionExpressionGrammarAction($1, $3); }
	| expression MUL expression									{ $$ = MultiplicationExpressionGrammarAction($1, $3); }
	| expression DIV expression									{ $$ = DivisionExpressionGrammarAction($1, $3); }
	| expression POW expression									{ GenericLogger("PowExpressionGrammarAction"); }
	| SQRT OPEN_PARENTHESIS expression CLOSE_PARENTHESIS		{ GenericLogger("SqrtExpressionGrammarAction"); }
	| factor FACT												{ $$ = FactorialExpressionGrammarAction($1); }
	| factor													{ $$ = FactorExpressionGrammarAction($1); }
	;

if: IF OPEN_PARENTHESIS condition CLOSE_PARENTHESIS OPEN_BRACE block end_if
	;

end_if: CLOSE_BRACE												{ GenericLogger("CloseBraceGrammarAction"); }
	| CLOSE_BRACE ELSE OPEN_BRACE block CLOSE_BRACE				{ GenericLogger("ElseGrammarAction"); }

condition: factor compare_opt factor							{ GenericLogger("ConditionGrammarAction"); }
	;

block: instruction block										{ GenericLogger("InstructionBlockGrammarAction"); }
	| EOL block													{ GenericLogger("EOLBlockGrammarAction"); }
	| instruction												{ GenericLogger("InstructionGrammarAction"); }
	| EOL														{ GenericLogger("EOLGrammarAction"); }
	;

compare_opt: EQ
	| NE
	| LE
	| GE
	| LT
	| GT
	;

declare: type VARIABLE_NAME ASSIGN value	   					{ $$ = DeclareVariableGrammarAction($1, $2, $4); }
	| dist_declare												{ printf("Result: %d", $1); } 
	| type VARIABLE_NAME ASSIGN input							{ printf("Result: %d", $1); }
	;

foreach: FOREACH OPEN_PARENTHESIS stat_function_arg COMMA foreach_func_arg COMMA INTEGER COMMA INTEGER CLOSE_PARENTHESIS
	;

foreach_func_arg: PRINT
	| SQRT
	| FACT
	| ADD
	| MUL
	;

input: INPUT OPEN_PARENTHESIS CLOSE_PARENTHESIS

print: PRINT OPEN_PARENTHESIS print_args CLOSE_PARENTHESIS
	;

print_args: STRING ADD print_args
	| VARIABLE_NAME ADD print_args
	| expression ADD print_args
	| STRING
	| VARIABLE_NAME
	| expression
	;

stat_function: stat_function_type OPEN_PARENTHESIS stat_function_arg CLOSE_PARENTHESIS
	;	

stat_function_arg: VARIABLE_NAME
	| LIST
	;


stat_function_type: MEAN 
	| MODE 
	| VARIANCE
	| KURTOSIS
	| Q1
	| Q3
	| MAX
	| MIN
	| SD
	| SKEWNESS
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
	;

normal_type: NORMAL_DIST_TYPE OPEN_PARENTHESIS FLOAT COMMA FLOAT CLOSE_PARENTHESIS
	| NORMAL_DIST_TYPE OPEN_PARENTHESIS VARIABLE_NAME COMMA VARIABLE_NAME CLOSE_PARENTHESIS
	| NORMAL_DIST_TYPE OPEN_PARENTHESIS VARIABLE_NAME SUM_WITH VARIABLE_NAME CLOSE_PARENTHESIS
	;

poisson_type: POISSON_DIST_TYPE OPEN_PARENTHESIS INTEGER CLOSE_PARENTHESIS
	;

factor: OPEN_PARENTHESIS expression CLOSE_PARENTHESIS			{ $$ = ExpressionFactorGrammarAction($2); }
	| value														{ $$ = $1; }
	;

value: constant													{ $$ = ConstantFactorGrammarAction($1); }
	| VARIABLE_NAME												{ $$ = AddVariableReferenceGrammarAction($1); }
	| stat_function												{ GenericLogger("StatFuntionGrammarAction"); }
	;

constant: INTEGER												{ $$ = IntegerConstantGrammarAction($1); }
	| FLOAT														{ $$ = FloatConstantGrammarAction($1); }
	| STRING													{ $$ = StringConstantGrammarAction($1); }
	| LIST														{ $$ = ListConstantGrammarAction($1); }
	;

%%
