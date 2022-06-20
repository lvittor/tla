%{

#include "bison-actions.h"

%}

%union {
	// Terminales
	char * string;
	int integer;
	yytoken_kind_t token;
	double decimal;

	// No terminales
	Main * main;
	Program * program;
	Instructions * instructions;
	Instruction * instruction;
	Statement * statement;
	Expression * expression;
	If * _if;
	EndIf * _endif;
	Condition * condition;
	Block * block;
	CompareOpt * compare_opt;
	Declare * declare;
	Foreach * foreach;
	ForeachFunctionArg * foreach_func_arg;
	Input * input;
	Print * print;
	StatFunction * stat_function;
	StatFunctionType * stat_function_type;
	Token * token_node;
	DistDeclare * dist_declare;
	DistType * dist_type;
	Binomial * binomial;
	Normal * normal;
	Poisson * poisson;
	Factor * factor;
	Value * value;
	List * list;
	Numeric * numeric;
	Text * text;
}

// Terminales
%token <token> MAIN
%token <token> SEMICOLON
%token <token> ADD SUB MUL DIV FACT POW SQRT
%token <token> OPEN_PARENTHESIS CLOSE_PARENTHESIS
%token <token> OPEN_BRACE CLOSE_BRACE
%token <token> ASSIGN
%token <token> EQ NE LE GE LT GT
%token <token> SUM_WITH
%token <token> IF ELSE
%token <token> FOREACH
%token <token> COMMA
%token <token> INTEGER_TYPE FLOAT_TYPE STRING_TYPE LIST_TYPE
%token <token> BINOMIAL_DIST_TYPE NORMAL_DIST_TYPE POISSON_DIST_TYPE
%token <token> PRINT INPUT
%token <token> MEAN MODE VARIANCE KURTOSIS Q1 Q3 MAX MIN SD SKEWNESS
%token <integer> INTEGER 
%token <decimal> FLOAT 
%token <string> STRING LIST VARIABLE_NAME
%token <token> EOL EOFF

// No terminales
%type <main> main
%type <program> program
%type <instructions> instructions
%type <instruction> instruction
%type <statement> statement
%type <expression> expression
%type <_if> if
%type <_endif> end_if
%type <condition> condition
%type <block> block
%type <compare_opt> compare_opt
%type <declare> declare
%type <foreach> foreach
%type <foreach_func_arg> foreach_func_arg
%type <input> input
%type <print> print
%type <stat_function> stat_function
%type <stat_function_type> stat_function_type
%type <token_node> type
%type <dist_declare> dist_declare
%type <dist_type> dist_type
%type <binomial> binomial_type
%type <normal> normal_type
%type <poisson> poisson_type
%type <factor> factor
%type <value> value
%type <list> list_value
%type <numeric> numeric_value
%type <text> text_value
%type <string> symbol

// Reglas de asociatividad y precedencia (de menor a mayor):
%left ADD SUB
%left MUL DIV
%left EQ NE LT LE GT GE
%left FACT
%left POW

%start main

%%

main: MAIN OPEN_BRACE program CLOSE_BRACE						{ $$ = MainGrammarAction($3); }
	;

program: instructions											{ $$ = ProgramGrammarAction($1); } 
	;

instructions: instruction instructions							{ $$ = InstructionsGrammarAction($1, $2); }
	|	instruction												{ $$ = InstructionOneGrammarAction($1); }
	;

instruction: statement SEMICOLON								{ $$ = InstructionStatementGrammarAction($1); }
	| if														{ $$ = InstructionIfGrammarAction($1); }
	;

statement: declare												{ $$ = StatementDeclareGrammarAction($1); }
	| print														{ $$ = StatementPrintGrammarAction($1); }
	| foreach													{ $$ = StatementForeachGrammarAction($1); }
	;

expression: expression ADD expression							{ $$ = ExpressionAdditionGrammarAction($1, $3); }
	| expression SUB expression									{ $$ = ExpressionSubtractionGrammarAction($1, $3); }
	| expression MUL expression									{ $$ = ExpressionMultiplicationGrammarAction($1, $3); }
	| expression DIV expression									{ $$ = ExpressionDivisionGrammarAction($1, $3); }
	| expression POW expression									{ $$ = ExpressionPowerGrammarAction($1, $3); }
	| SQRT OPEN_PARENTHESIS expression CLOSE_PARENTHESIS		{ $$ = ExpressionSqrtGrammarAction($3); }
	| factor FACT												{ $$ = ExpressionFactorialGrammarAction($1); }
	| factor													{ $$ = ExpressionFactorGrammarAction($1); }
	;

if: IF OPEN_PARENTHESIS condition CLOSE_PARENTHESIS OPEN_BRACE block end_if		{ $$ = IfGrammarAction($3, $6, $7); }
	;

end_if: CLOSE_BRACE												{ $$ = EndIfCloseBraceGrammarAction(); }
	| CLOSE_BRACE ELSE OPEN_BRACE block CLOSE_BRACE				{ $$ = EndIfElseGrammarAction($4); }
	;

condition: factor compare_opt factor							{ $$ = ConditionGrammarAction($1, $2, $3); }
	;

block: instructions												{ $$ = BlockGrammarAction($1); }
	;

compare_opt: EQ													{ $$ = CompareEQGrammarAction($1); }
	| NE														{ $$ = CompareNEGrammarAction($1); }
	| LE														{ $$ = CompareLEGrammarAction($1); }
	| GE														{ $$ = CompareGEGrammarAction($1); }
	| LT														{ $$ = CompareLTGrammarAction($1); }
	| GT														{ $$ = CompareGTGrammarAction($1); }
	;

declare: type symbol ASSIGN expression	   						{ $$ = DeclareVariableGrammarAction($1, $2, $4); }
	| dist_declare												{ $$ = DeclareDistributionGrammarAction($1); } 
	| type symbol ASSIGN input									{ $$ = DeclareInputGrammarAction($1, $2, $4); }
	;

foreach: FOREACH OPEN_PARENTHESIS list_value COMMA foreach_func_arg COMMA INTEGER COMMA INTEGER CLOSE_PARENTHESIS	{ $$ = ForeachGrammarAction($3, $5, $7, $9); }
	| FOREACH OPEN_PARENTHESIS symbol COMMA foreach_func_arg COMMA INTEGER COMMA INTEGER CLOSE_PARENTHESIS	{ $$ = ForeachVariableGrammarAction($3, $5, $7, $9); }
	;

foreach_func_arg: PRINT											{ $$ = ForeachFuncArgPrintGrammarAction($1); }
	| SQRT														{ $$ = ForeachFuncArgSqrtGrammarAction($1); }
	| FACT														{ $$ = ForeachFuncArgFactGrammarAction($1); }
	| ADD														{ $$ = ForeachFuncArgAddGrammarAction($1); }
	| MUL														{ $$ = ForeachFuncArgMulGrammarAction($1); }
	;

input: INPUT OPEN_PARENTHESIS CLOSE_PARENTHESIS					{ InputGrammarAction(); }
	;

print: PRINT OPEN_PARENTHESIS expression CLOSE_PARENTHESIS		{ $$ = PrintGrammarAction($3); }
	;

stat_function: stat_function_type OPEN_PARENTHESIS list_value CLOSE_PARENTHESIS 	{ $$ = StatFunctionGrammarAction($1, $3); }
	| stat_function_type OPEN_PARENTHESIS symbol CLOSE_PARENTHESIS 					{ $$ = StatFunctionVariableGrammarAction($1, $3); }
	;	

stat_function_type: MEAN										{ $$ = StatFunctionTypeMeanGrammarAction($1); } 
	| MODE 														{ $$ = StatFunctionTypeModeGrammarAction($1); } 
	| VARIANCE													{ $$ = StatFunctionTypeVarianceGrammarAction($1); } 
	| KURTOSIS													{ $$ = StatFunctionTypeKurtosisGrammarAction($1); } 
	| Q1														{ $$ = StatFunctionTypeQ1GrammarAction($1); } 
	| Q3														{ $$ = StatFunctionTypeQ3GrammarAction($1); } 
	| MAX														{ $$ = StatFunctionTypeMaxGrammarAction($1); } 
	| MIN														{ $$ = StatFunctionTypeMinGrammarAction($1); } 
	| SD														{ $$ = StatFunctionTypeSdGrammarAction($1); } 
	| SKEWNESS													{ $$ = StatFunctionTypeSkewnessGrammarAction($1); } 
	;

type: INTEGER_TYPE												{ $$ = TypeIntegerGrammarAction($1); }												
	| FLOAT_TYPE 												{ $$ = TypeFloatGrammarAction($1); }												
	| STRING_TYPE 												{ $$ = TypeStringGrammarAction($1); }												
	| LIST_TYPE													{ $$ = TypeListGrammarAction($1); }												
	;

dist_declare: dist_type symbol									{ $$ = DistDeclareGrammarAction($1, $2); }
	;

dist_type: binomial_type										{ $$ = DistTypeBinomialGrammarAction($1); }
	| normal_type												{ $$ = DistTypeNormalGrammarAction($1); }
	| poisson_type												{ $$ = DistTypePoissonGrammarAction($1); }
	;

binomial_type:  BINOMIAL_DIST_TYPE OPEN_PARENTHESIS INTEGER COMMA FLOAT CLOSE_PARENTHESIS	 	{ $$ = BinomialTypeValuesGrammarAction($3, $5); }			
	| BINOMIAL_DIST_TYPE OPEN_PARENTHESIS symbol COMMA symbol CLOSE_PARENTHESIS					{ $$ = BinomialTypeVariablesGrammarAction($3, $5); }		
	;

normal_type: NORMAL_DIST_TYPE OPEN_PARENTHESIS FLOAT COMMA FLOAT CLOSE_PARENTHESIS		      	{ $$ = NormalTypeValuesGrammarAction($3, $5); } 			  	 
	| NORMAL_DIST_TYPE OPEN_PARENTHESIS symbol COMMA symbol CLOSE_PARENTHESIS   				{ $$ = NormalTypeVariableGrammarAction($3, $5); }   	 
	| NORMAL_DIST_TYPE OPEN_PARENTHESIS symbol SUM_WITH symbol CLOSE_PARENTHESIS				{ $$ = NormalTypeSumGrammarAction($3, $5); } 
	;

poisson_type: POISSON_DIST_TYPE OPEN_PARENTHESIS INTEGER CLOSE_PARENTHESIS                      { $$ = PoissonTypeValueGrammarAction($3); }
	| POISSON_DIST_TYPE OPEN_PARENTHESIS symbol CLOSE_PARENTHESIS                         		{ $$ = PoissonTypeVariableGrammarAction($3); }
	;

factor: OPEN_PARENTHESIS expression CLOSE_PARENTHESIS			{ $$ = FactorExpressionGrammarAction($2); }
	| value														{ $$ = FactorVariableGrammarAction($1); }
	;

value: numeric_value											{ $$ = ValueNumericGrammarAction($1); }
	| text_value												{ $$ = ValueTextGrammarAction($1); }
	| symbol													{ $$ = ValueVariableGrammarAction($1); }
	| list_value												{ $$ = ValueListGrammarAction($1); }
	;

list_value: LIST												{ $$ = ListGrammarAction($1); }
	;

numeric_value: INTEGER											{ $$ = NumericIntegerGrammarAction($1); }
	| FLOAT														{ $$ = NumericFloatGrammarAction($1); }
	| stat_function												{ $$ = NumericStatGrammarAction($1); }
	;

symbol: VARIABLE_NAME											{ $$ = SymbolGrammarAction($1); }
	;

text_value: STRING												{ $$ = TextGrammarAction($1); }
	;

%%
