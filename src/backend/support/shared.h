#ifndef SHARED_HEADER
#define SHARED_HEADER

#include <stdio.h>

// Descriptor del archivo de entrada que utiliza Bison.
extern FILE * yyin;

// Descriptor del archivo de salida que utiliza Bison.
extern FILE * yyout;

// Variable global que contiene el número escaneado.
// extern int yylval;

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

typedef struct Program;
typedef struct Instructions;
typedef struct Instruction;
typedef struct Expression;
typedef struct If;
typedef struct EndIf;
typedef struct Condition;
typedef struct Block;
typedef struct CompareOpt;
typedef struct Declare;
typedef struct Foreach;
typedef struct ForeachFunctionArg;
typedef struct Input;
typedef struct Print;
typedef struct PrintArgs;
typedef struct StatFunction;
typedef struct StatFunctionArg;
typedef struct StatFunctionType;
typedef struct Token;
typedef struct DistDeclare;
typedef struct DistType;
typedef struct Binomial;
typedef struct Normal;
typedef struct Poisson;
typedef struct Factor;
typedef struct Value;
typedef struct List;
typedef struct Numeric;
typedef struct Text;

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

	Program * program;

} CompilerState;

// El estado se define e inicializa en el archivo "main.c":
extern CompilerState state;

typedef struct Program {
	Instructions * instructions;
} Program;

typedef enum InstructionsType {
	EOL_INSTRUCTIONS,
	INSTRUCTION_INSTRUCTIONS
} InstructionsType;

typedef struct Instructions {
	InstructionsType type;
	Instruction * instruction;
	Instructions * instructions;
} Instructions;

typedef enum InstructionType {
	DECLARE_INSTRUCTION,
	PRINT_INSTRUCTION,
	IF_INSTRUCTION,
	FOREACH_INSTRUCTION
} InstructionType;

typedef struct Instruction {
	InstructionType type;
	Declare * declare_instruction;
	Print * print_instruction;
	If * if_instruction;
	Foreach * foreach_instruction;
} Instruction;

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
	VALUE_DECLARE,
	DIST_DECLARE,
	INPUT_DECLARE
} DeclareType;

// tengo dudas
typedef struct Declare { 
	DeclareType type;
	Token * type_token;
	char * variable_name;
	DistDeclare * dist_declare;
	Value * value;
	Input * input;
} Declare;

typedef struct Foreach {
	StatFunctionArg * stat_function_arg;
	ForeachFunctionArg * foreach_function_arg;
	int left_value;
	int right_value;
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

// ?????????/
typedef struct Input {
	char * value;
} Input;

typedef struct Print {
	PrintArgs * print_args;
} Print;

typedef enum PrintArgsType {
	TEXT_ADD_TYPE,
	VAR_ADD_TYPE,
	EXPRESSION_ADD_TYPE,
	TEXT_TYPE,
	VAR_TYPE,
	EXPRESSION_TYPE
} PrintArgsType;

typedef struct PrintArgs {
	PrintArgsType type;
	Text * text_value;
	PrintArgs * print_args;
	Expression * expression;
	char * variable_name;
} PrintArgs;

typedef struct StatFunction {
	StatFunctionType * stat_function_type;
	StatFunctionArg * stat_function_arg;
} StatFunction;

typedef enum StatFunctionArgType {
	LIST_STAT_ARG,
	VARIABLE_STAT_ARG
} StatFunctionArgType;

typedef struct StatFunctionArg {
	StatFunctionArgType type;
	List * list_value;
	char * variable_name;
} StatFunctionArg;

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
	INTEGER_TYPE,
	FLOAT_TYPE,
	STRING_TYPE,
	LIST_TYPE	
} TokenType;

typedef struct Token {
	TokenType type;
	int token;
} Token;

typedef struct DistDeclare {
	DistType * dist_type;
	char * variable_name;
} DistDeclare;

typedef struct DistType {
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
	float float_value;
} Binomial;

typedef enum NormalType {
	FLOAT_FLOAT_NORMAL,
	VARIABLE_VARIABLE_NORMAL,
	VARIABLE_SUM_VARIABLE_NORMAL
} NormalType;

typedef struct Normal {
	NormalType type;
	float left_float;
	float right_float;
	char * left_variable_name;
	char * right_variable_name;
} Normal;

typedef enum PoissonType {
	INTEGER_POISSON,
	VARIABLE_POISSON
} PoissonType;

typedef struct Poisson {
	PoissonType type;
	int value;
	char * variable_name;
} Poisson;

typedef enum FactorType {
	EXPRESSION_FACTOR,
	NUMERIC_FACTOR,
	VARIABLE_FACTOR
} FactorType;

typedef struct Factor {
	FactorType type;
	Expression * expression;
	Numeric * numeric_value;
	char * variable_name;
} Factor;

typedef enum ValueType {
	NUMERIC_VALUE,
	TEXT_VALUE,
	LIST_VALUE,
	EXPRESSION_VALUE,
	VARIABLE_VALUE
} ValueType;

typedef struct Value {
	Numeric * numeric_value;
	Text * text_value;
	List * list_value;
	Expression * expression;
	char * variable_name;
} Value;

typedef struct List {
	char * list;
} List;

typedef enum NumericType {
	INTEGER_NUMERIC,
	FLOAT_NUMERIC,
	STAT_NUMERIC
} NumericType;

typedef struct Numeric {
	NumericType type;
	int int_value;
	float float_value;
	StatFunction * stat_function;
} Numeric;

typedef struct Text {
	char * value;
} Text;









#endif
