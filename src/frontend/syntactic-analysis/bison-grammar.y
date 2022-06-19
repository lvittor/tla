%{

#include "bison-actions.h"

%}

%union {
	// Terminales
	char * string;
	int integer;
	int token;
	double float;

	// No terminales
	Program * program;
	Instructions * instructions;
	Instruction * instruction;
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
	PrintArgs * print_args;
	StatFunction * stat_function;
	StatFunctionArg * stat_function_arg;
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
%token <float> FLOAT 
%token <string> STRING LIST VARIABLE_NAME
%token <token> EOL EOFF

// No terminales
%type <program> program
%type <instructions> instructions
%type <instruction> instruction
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
%type <print_args> print_args
%type <stat_function> stat_function
%type <stat_function_arg> stat_function_arg
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

// Reglas de asociatividad y precedencia (de menor a mayor):
%left ADD SUB
%left MUL DIV
%left FACT

%start program

%%

program: instructions											{ $$ = ProgramGrammarAction($1); } 
	;

instructions: instruction EOL instructions						{ $$ = InstructionsEOLGrammarAction($1, $3); }
	|	instruction												{ $$ = InstructionsGrammarAction($1); }
	;

instruction: declare											{ $$ = InstructionDeclareGrammarAction($1); }
	| print														{ $$ = InstructionPrintGrammarAction($1); }
	| if														{ $$ = InstructionIfGrammarAction($1); }
	| foreach													{ $$ = InstructionForeachGrammarAction($1); }
	;

expression: expression ADD expression							{ $$ = AdditionExpressionGrammarAction($1, $3); }
	| expression SUB expression									{ $$ = SubtractionExpressionGrammarAction($1, $3); }
	| expression MUL expression									{ $$ = MultiplicationExpressionGrammarAction($1, $3); }
	| expression DIV expression									{ $$ = DivisionExpressionGrammarAction($1, $3); }
	| expression POW expression									{ $$ = PowerExpressionGrammarAction($1, $3); }
	| SQRT OPEN_PARENTHESIS expression CLOSE_PARENTHESIS		{ $$ = SqrtExpressionGrammarAction($3); }
	| factor FACT												{ $$ = FactorialExpressionGrammarAction($1); }
	| factor													{ $$ = FactorExpressionGrammarAction($1); }
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

declare: type VARIABLE_NAME ASSIGN value	   					{ $$ = DeclareVariableGrammarAction($1, $2, $4); }
	| dist_declare												{ $$ = DeclareDistributionGrammarAction($1); } 
	| type VARIABLE_NAME ASSIGN input							{ $$ = DeclareInputGrammarAction($1, $2, $4); }
	;

foreach: FOREACH OPEN_PARENTHESIS stat_function_arg COMMA foreach_func_arg COMMA INTEGER COMMA INTEGER CLOSE_PARENTHESIS	{ $$ = ForeachGrammarAction($3, $5, $7, $9); }
	;

foreach_func_arg: PRINT											{ $$ = ForeachFuncArgPrintGrammarAction($1); }
	| SQRT														{ $$ = ForeachFuncArgSqrtGrammarAction($1); }
	| FACT														{ $$ = ForeachFuncArgFactGrammarAction($1); }
	| ADD														{ $$ = ForeachFuncArgAddGrammarAction($1); }
	| MUL														{ $$ = ForeachFuncArgMulGrammarAction($1); }
	;

input: INPUT OPEN_PARENTHESIS CLOSE_PARENTHESIS					{ $$ = InputGrammarAction(); }

print: PRINT OPEN_PARENTHESIS print_args CLOSE_PARENTHESIS		{ $$ = PrintGrammarAction($3); }
	;

print_args: text_value ADD print_args							{ $$ = PrintArgsTextAddGrammarAction($1, $2); }
	| VARIABLE_NAME ADD print_args								{ $$ = PrintArgsVariableAddGrammarAction($1, $2); }
	| expression ADD print_args									{ $$ = PrintArgsExpressionAddGrammarAction($1, $2); }
	| text_value												{ $$ = PrintArgsTextGrammarAction($1); }
	| VARIABLE_NAME												{ $$ = PrintArgsVariableGrammarAction($1); }
	| expression												{ $$ = PrintArgsExpressionGrammarAction($1); }
	;

stat_function: stat_function_type OPEN_PARENTHESIS stat_function_arg CLOSE_PARENTHESIS { $$ = StatFunctionGrammarAction($1, $3); }
	;	

stat_function_arg: list_value									{ $$ = StatFunctionArgListGrammarAction($1); }
	| VARIABLE_NAME												{ $$ = StatFunctionArgVariableGrammarAction($1); }
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

dist_declare: dist_type VARIABLE_NAME							{ $$ = DistDeclareGrammarAction($1, $2); }
	;

dist_type: binomial_type										{ $$ = DistTypeBinomialGrammarAction($1); }
	| normal_type												{ $$ = DistTypeNormalGrammarAction($1); }
	| poisson_type												{ $$ = DistTypePoissonGrammarAction($1); }
	;

binomial_type:  BINOMIAL_DIST_TYPE OPEN_PARENTHESIS INTEGER COMMA FLOAT CLOSE_PARENTHESIS	 	{ $$ = BinomialTypeValuesGrammarAction($3, $5); }			
	| BINOMIAL_DIST_TYPE OPEN_PARENTHESIS VARIABLE_NAME COMMA VARIABLE_NAME CLOSE_PARENTHESIS	{ $$ = BinomialTypeVariablesGrammarAction($3, $5); }		
	;

normal_type: NORMAL_DIST_TYPE OPEN_PARENTHESIS FLOAT COMMA FLOAT CLOSE_PARENTHESIS
	| NORMAL_DIST_TYPE OPEN_PARENTHESIS VARIABLE_NAME COMMA VARIABLE_NAME CLOSE_PARENTHESIS
	| NORMAL_DIST_TYPE OPEN_PARENTHESIS VARIABLE_NAME SUM_WITH VARIABLE_NAME CLOSE_PARENTHESIS
	;

poisson_type: POISSON_DIST_TYPE OPEN_PARENTHESIS INTEGER CLOSE_PARENTHESIS
	| POISSON_DIST_TYPE OPEN_PARENTHESIS VARIABLE_NAME CLOSE_PARENTHESIS
	;

factor: OPEN_PARENTHESIS expression CLOSE_PARENTHESIS			{ $$ = ExpressionFactorGrammarAction($2); }
	| numeric_value												{ $$ = $1; }
	| VARIABLE_NAME												{ $$ = $1; }
	;

value: numeric_value											{ $$ = $1; }
	| text_value												{ $$ = $1; }
	| list_value												{ $$ = $1; }
	| expression
	| VARIABLE_NAME												{ $$ = AddVariableReferenceGrammarAction($1); }
	;

list_value: LIST												{ $$ = ListConstantGrammarAction($1); }
	;

numeric_value: INTEGER											{ $$ = IntegerConstantGrammarAction($1); }
	| FLOAT														{ $$ = FloatConstantGrammarAction($1); }
	| stat_function												{ GenericLogger("StatFuntionGrammarAction"); }
	;

text_value: STRING												{ $$ = StringConstantGrammarAction($1); }
	;

%%
