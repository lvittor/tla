#ifndef SHARED_HEADER
#define SHARED_HEADER

#include <stdio.h>

// Descriptor del archivo de entrada que utiliza Bison.
extern FILE * yyin;

// Descriptor del archivo de salida que utiliza Bison.
extern FILE * yyout;

// Variable global que contiene el número escaneado.
// extern int yylval;

// Variable global que contiene el largo obtenido en yytext
extern int yyleng;

// Variable global que contiene el número de la línea analizada.
extern int yylineno;

// Token actual en el tope de la pila del analizador Bison.
extern char * yytext;

// Función global de manejo de errores en Bison.
extern void yyerror(const char * string);

// Función global del analizador léxico Flex.
extern int yylex(void);

// Función global del analizador sintáctico Bison.
extern int yyparse(void);

typedef struct Main Main;
typedef struct Program Program;
typedef struct Instructions Instructions;
typedef struct Instruction Instruction;
typedef struct Statement Statement;
typedef struct Expression Expression;
typedef struct If If;
typedef struct EndIf EndIf;
typedef struct Condition Condition;
typedef struct Block Block;
typedef struct CompareOpt CompareOpt;
typedef struct Declare Declare;
typedef struct Foreach Foreach;
typedef struct ForeachFunctionArg ForeachFunctionArg;
typedef struct Input Input;
typedef struct Print Print;
typedef struct StatFunction StatFunction;
typedef struct StatFunctionType StatFunctionType;
typedef struct Token Token;
typedef struct DistDeclare DistDeclare;
typedef struct DistType DistType;
typedef struct Binomial Binomial;
typedef struct Normal Normal;
typedef struct Poisson Poisson;
typedef struct Factor Factor;
typedef struct Value Value;
typedef struct List List;
typedef struct Numeric Numeric;
typedef struct Text Text;

// Emular tipo "boolean".
typedef enum {
	false = 0,
	true = 1
} boolean;

// Estado global de toda la aplicación.
typedef struct {

	// Indica si la compilación tuvo problemas hasta el momento:
	boolean succeed;

	// Indica el resultado de la compilación:
	int result;

	// Agregar una pila para almacenar tokens/nodos.
	// Agregar un nodo hacia la raíz del árbol de sintaxis abstracta.
	// Agregar una tabla de símbolos.
	// ...

	Main * main;

} CompilerState;

// El estado se define e inicializa en el archivo "main.c":
extern CompilerState state;

typedef struct Main {
	Program * program;
} Main;

typedef struct Program {
	Instructions * instructions;
} Program;

typedef enum InstructionsType {
	INSTRUCTION_INSTRUCTIONS,
	ONE_INSTRUCTIONS
} InstructionsType;

typedef struct Instructions {
	InstructionsType type;
	Instruction * instruction;
	Instructions * instructions;
} Instructions;

typedef enum InstructionType {
	STATEMENT_INSTRUCTION,
	IF_INSTRUCTION,
} InstructionType;

typedef struct Instruction {
	InstructionType type;
	Statement * statement_instruction;
	If * if_instruction;
} Instruction;

typedef enum StatementType {
	PRINT_STATEMENT,
	DECLARE_STATEMENT,
	FOREACH_STATEMENT,
} StatementType;

typedef struct Statement {
	StatementType type;
	Declare * declare_statement;
	Print * print_statement;
	Foreach * foreach_statement;
} Statement;

typedef enum ExpressionType {
	ADD_EXPRESSION,
	SUB_EXPRESSION,
	MUL_EXPRESSION,
	DIV_EXPRESSION,
	POW_EXPRESSION,
	SQRT_EXPRESSION,
	FACT_EXPRESSION,
	FACTOR_EXPRESSION
} ExpressionType;

typedef struct Expression {
	ExpressionType type;
	Expression * left_expression;
	Expression * right_expression;
	Factor * factor_expression;
} Expression;

typedef struct If {
	Condition * condition;
	Block * block;
	EndIf * end_if;
} If;

typedef enum EndIfType {
	CLOSE_NORMAL,
	CLOSE_BLOCK
} EndIfType;

typedef struct EndIf {
	EndIfType type;
	Block * block;
} EndIf;

typedef struct Condition {
	Factor * left_factor;
	Factor * right_factor;
	CompareOpt * compare_opt;
} Condition;

typedef struct Block {
	Instructions * instructions;
} Block;

typedef enum CompareOptType {
	EQ_COMPARE,
	NE_COMPARE,
	LE_COMPARE,
	GE_COMPARE,
	LT_COMPARE,
	GT_COMPARE
} CompareOptType;

typedef struct CompareOpt {
	CompareOptType type;
	int comparator;
} CompareOpt;

typedef enum DeclareType {
	EXPRESSION_DECLARE,
	DIST_DECLARE,
	INPUT_DECLARE
} DeclareType;

typedef struct Declare { 
	DeclareType type;
	Token * type_token;
	char * variable_name;
	DistDeclare * dist_declare;
	Expression * expression;
	Input * input;
} Declare;

typedef enum ForeachType {
	LIST_FOREACH,
	VARIABLE_FOREACH
} ForeachType;

typedef struct Foreach {
	ForeachType type;
	List * list_value;
	ForeachFunctionArg * foreach_function_arg;
	int left_value;
	int right_value;
	char * variable_name;
} Foreach;

typedef enum ForeachFuncArgType {
	PRINT_FOREACH,
	SQRT_FOREACH,
	FACT_FOREACH,
	ADD_FOREACH,
	MUL_FOREACH
} ForeachFuncArgType;

typedef struct ForeachFunctionArg {
	ForeachFuncArgType type;
	int function;
} ForeachFunctionArg;

typedef struct Input {
	char * value;
} Input;

typedef struct Print {
	Expression * expression;
} Print;

typedef enum StatFunctionTypeToken {
	LIST_STAT_FUNCTION,
	VARIABLE_STAT_FUNCTION
} StatFunctionTypeToken;

typedef struct StatFunction {
	StatFunctionTypeToken type;
	StatFunctionType * stat_function_type;
	List * list_value;
	char * variable_name;
} StatFunction;

typedef enum StatFunctionTypeType {
	MEAN_STAT_TYPE,
	MODE_STAT_TYPE,
	VARIANCE_STAT_TYPE,
	KURTOSIS_STAT_TYPE,
	Q1_STAT_TYPE,
	Q3_STAT_TYPE,
	MAX_STAT_TYPE,
	MIN_STAT_TYPE,
	SD_STAT_TYPE,
	SKEWNESS_STAT_TYPE
} StatFunctionTypeType;

typedef struct StatFunctionType {
	StatFunctionTypeType type;
	int stat_function;
} StatFunctionType;

typedef enum TokenType {
	INTEGER_TOKEN_TYPE,
	FLOAT_TOKEN_TYPE,
	STRING_TOKEN_TYPE,
	LIST_TOKEN_TYPE	
} TokenType;

typedef struct Token {
	TokenType type;
	int token;
} Token;

typedef struct DistDeclare {
	DistType * dist_type;
	char * variable_name;
} DistDeclare;

typedef enum DistTypeType {
	BINOMIAL_TYPE,
	NORMAL_TYPE,
	POISSON_TYPE
} DistTypeType;

typedef struct DistType {
	DistTypeType type;
	Binomial * binomial;
	Normal * normal;
	Poisson * poisson;
} DistType;

typedef enum BinomialType {
	INTEGER_FLOAT_BINOMIAL,
	VARIABLE_VARIABLE_BINOMIAL
} BinomialType;

typedef struct Binomial {
	BinomialType type;
	char * left_variable_name;
	char * right_variable_name;
	int int_value;
	double float_value;
} Binomial;

typedef enum NormalType {
	FLOAT_FLOAT_NORMAL,
	VARIABLE_VARIABLE_NORMAL,
	VARIABLE_SUM_VARIABLE_NORMAL
} NormalType;

typedef struct Normal {
	NormalType type;
	double left_float;
	double right_float;
	char * left_variable_name;
	char * right_variable_name;
} Normal;

typedef enum PoissonType {
	INTEGER_POISSON,
	VARIABLE_POISSON
} PoissonType;

typedef struct Poisson {
	PoissonType type;
	int int_value;
	char * variable_name;
} Poisson;

typedef enum FactorType {
	EXPRESSION_FACTOR,
	VALUE_FACTOR
} FactorType;

typedef struct Factor {
	FactorType type;
	Expression * expression;
	Value * value;
} Factor;

typedef enum ValueType {
	NUMERIC_VALUE,
	TEXT_VALUE,
	LIST_VALUE,
	VARIABLE_VALUE
} ValueType;

typedef struct Value {
	ValueType type;
	Numeric * numeric_value;
	Text * text_value;
	List * list_value;
	char * variable_name;
} Value;

typedef struct List {
	char * list_value;
} List;

typedef enum NumericType {
	INTEGER_NUMERIC,
	FLOAT_NUMERIC,
	STAT_NUMERIC
} NumericType;

typedef struct Numeric {
	NumericType type;
	int int_value;
	double float_value;
	StatFunction * stat_function;
} Numeric;

typedef struct Text {
	char * text_value;
} Text;









#endif
