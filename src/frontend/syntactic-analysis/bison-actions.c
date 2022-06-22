#include "../../backend/support/logger.h"
#include "../../backend/support/get-types.h"
#include "../../backend/semantic-analysis/symbol-table.h"
#include "bison-actions.h"
#include "bison-parser.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Implementación de "bison-grammar.h".
 */

void yyerror(const char * string) {
	LogError("	Mensaje: '%s' debido a '%s' (linea %d).", string, yytext, yylineno);
	LogError("	En ASCII es:");
	LogErrorRaw("\t");
	const int length = strlen(yytext);
	for (int i = 0; i < length; ++i) {
		LogErrorRaw("[%d]", yytext[i]);
	}
	LogErrorRaw("\n\n");
}

void GenericLogger(const char * string){
    LogDebug("	%s", string);
}

Main * MainGrammarAction(Program * program) {
	GenericLogger("MainGrammarAction!");
	Main * newMain = malloc(sizeof(Main));
	newMain->program = program;
	state.succeed = true;
	state.main = newMain;
	return newMain;
}

Program * ProgramGrammarAction(Instructions * instructions) {
    GenericLogger("ProgramGrammarAction!");
    Program * newProgram = malloc(sizeof(Program));
	newProgram->instructions = instructions;
	return newProgram;
}

Instructions * InstructionsGrammarAction(Instruction * instruction, Instructions * instructions) {
	GenericLogger("InstructionsGrammarAction");
	Instructions * newInstructions = malloc(sizeof(Instructions));
	newInstructions->type = INSTRUCTION_INSTRUCTIONS;
	newInstructions->instruction = instruction;
	newInstructions->instructions = instructions;
	return newInstructions;
}

Instructions * InstructionOneGrammarAction(Instruction * instruction) {
	GenericLogger("InstructionOneGrammarAction");
	Instructions * newInstructions = malloc(sizeof(Instructions));
	newInstructions->type = ONE_INSTRUCTIONS;
	newInstructions->instruction = instruction;
	newInstructions->instructions = NULL;
	return newInstructions;
}

Instruction * InstructionStatementGrammarAction(Statement * statement_instruction) {
	GenericLogger("InstructionStatementGrammarAction");
	Instruction * newInstruction = malloc(sizeof(Instruction));
	newInstruction->type = STATEMENT_INSTRUCTION;
	newInstruction->statement_instruction = statement_instruction;
	newInstruction->if_instruction = NULL;
	return newInstruction;
}

Instruction * InstructionIfGrammarAction(If * if_instruction) {
	GenericLogger("InstructionIfGrammarAction");
	Instruction * newInstruction = malloc(sizeof(Instruction));
	newInstruction->type = IF_INSTRUCTION;
	newInstruction->statement_instruction = NULL;
	newInstruction->if_instruction = if_instruction;
	return newInstruction;
}

Statement * StatementDeclareGrammarAction(Declare * declare_statement) {
	GenericLogger("StatementDeclareGrammarAction");
	Statement * newStatement = malloc(sizeof(Statement));
	newStatement->type = DECLARE_STATEMENT;
	newStatement->declare_statement = declare_statement;
	newStatement->print_statement = NULL;
	newStatement->foreach_statement = NULL;
	return newStatement;
}

Statement * StatementPrintGrammarAction(Print * print_statement) {
	GenericLogger("StatementPrintGrammarAction");
	Statement * newStatement = malloc(sizeof(Statement));
	newStatement->type = PRINT_STATEMENT;
	newStatement->declare_statement = NULL;
	newStatement->print_statement = print_statement;
	newStatement->foreach_statement = NULL;
	return newStatement;
}

Statement * StatementForeachGrammarAction(Foreach * foreach_statement) {
	GenericLogger("StatementForeachGrammarAction");
	Statement * newStatement = malloc(sizeof(Statement));
	newStatement->type = FOREACH_STATEMENT;
	newStatement->declare_statement = NULL;
	newStatement->print_statement = NULL;
	newStatement->foreach_statement = foreach_statement;
	return newStatement;
}

Expression * ExpressionAdditionGrammarAction(Expression * left_expression, Expression * right_expression) {
	GenericLogger("ExpressionAdditionGrammarAction");
	int LEFT_TYPE = get_expression_type(left_expression);
	int RIGHT_TYPE = get_expression_type(right_expression);
	if (LEFT_TYPE == LIST_TOKEN_TYPE || LEFT_TYPE == STRING_TOKEN_TYPE) {
		LogError("Suma entre tipos incompatibles");
		exit(1);
	}
	if (RIGHT_TYPE == LIST_TOKEN_TYPE || RIGHT_TYPE == STRING_TOKEN_TYPE) {
		LogError("Suma entre tipos incompatibles");
		exit(1);
	}

	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = ADD_EXPRESSION;
	newExpression->left_expression = left_expression;
	newExpression->right_expression = right_expression;
	newExpression->factor_expression = NULL;
	return newExpression;
}

Expression * ExpressionSubtractionGrammarAction(Expression * left_expression, Expression * right_expression) {
	GenericLogger("ExpressionSubtractionGrammarAction");
	int LEFT_TYPE = get_expression_type(left_expression);
	int RIGHT_TYPE = get_expression_type(right_expression);
	if (LEFT_TYPE == LIST_TOKEN_TYPE || LEFT_TYPE == STRING_TOKEN_TYPE) {
		LogError("Resta entre tipos incompatibles");
		exit(1);
	}
	if (RIGHT_TYPE == LIST_TOKEN_TYPE || RIGHT_TYPE == STRING_TOKEN_TYPE) {
		LogError("Resta entre tipos incompatibles");
		exit(1);
	}

	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = SUB_EXPRESSION;
	newExpression->left_expression = left_expression;
	newExpression->right_expression = right_expression;
	newExpression->factor_expression = NULL;
	return newExpression;
}

Expression * ExpressionMultiplicationGrammarAction(Expression * left_expression, Expression * right_expression) {
	GenericLogger("ExpressionMultiplicationGrammarAction");
	int LEFT_TYPE = get_expression_type(left_expression);
	int RIGHT_TYPE = get_expression_type(right_expression);
	if (LEFT_TYPE == LIST_TOKEN_TYPE || LEFT_TYPE == STRING_TOKEN_TYPE) {
		LogError("Multiplicacion entre tipos incompatibles");
		exit(1);
	}
	if (RIGHT_TYPE == LIST_TOKEN_TYPE || RIGHT_TYPE == STRING_TOKEN_TYPE) {
		LogError("Multiplicacion entre tipos incompatibles");
		exit(1);
	}

	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = MUL_EXPRESSION;
	newExpression->left_expression = left_expression;
	newExpression->right_expression = right_expression;
	newExpression->factor_expression = NULL;
	return newExpression;
}

Expression * ExpressionDivisionGrammarAction(Expression * left_expression, Expression * right_expression) {
	GenericLogger("ExpressionDivisionGrammarAction");
	int LEFT_TYPE = get_expression_type(left_expression);
	int RIGHT_TYPE = get_expression_type(right_expression);
	if (LEFT_TYPE == LIST_TOKEN_TYPE || LEFT_TYPE == STRING_TOKEN_TYPE) {
		LogError("Division entre tipos incompatibles");
		exit(1);
	}
	if (RIGHT_TYPE == LIST_TOKEN_TYPE || RIGHT_TYPE == STRING_TOKEN_TYPE) {
		LogError("Division entre tipos incompatibles");
		exit(1);
	}

	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = DIV_EXPRESSION;
	newExpression->left_expression = left_expression;
	newExpression->right_expression = right_expression;
	newExpression->factor_expression = NULL;
	return newExpression;
}

Expression * ExpressionPowerGrammarAction(Expression * left_expression, Expression * right_expression) {
	GenericLogger("ExpressionPowerGrammarAction");
	int LEFT_TYPE = get_expression_type(left_expression);
	int RIGHT_TYPE = get_expression_type(right_expression);
	if (LEFT_TYPE == LIST_TOKEN_TYPE || LEFT_TYPE == STRING_TOKEN_TYPE) {
		LogError("Potenciacion entre tipos incompatibles");
		exit(1);
	}
	if (RIGHT_TYPE == LIST_TOKEN_TYPE || RIGHT_TYPE == STRING_TOKEN_TYPE) {
		LogError("Potenciacion entre tipos incompatibles");
		exit(1);
	}

	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = POW_EXPRESSION;
	newExpression->left_expression = left_expression;
	newExpression->right_expression = right_expression;
	newExpression->factor_expression = NULL;
	return newExpression;
}

Expression * ExpressionSqrtGrammarAction(Expression * expression) {
	GenericLogger("ExpressionSqrtGrammarAction");
	int TYPE = get_expression_type(expression);
	if (TYPE == LIST_TOKEN_TYPE || TYPE == STRING_TOKEN_TYPE) {
		LogError("Radicacion entre tipos incompatibles");
		exit(1);
	}

	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = SQRT_EXPRESSION;
	newExpression->left_expression = expression;
	newExpression->right_expression = NULL;
	newExpression->factor_expression = NULL;
	return newExpression;
}

Expression * ExpressionFactorialGrammarAction(Factor * factor) {
	GenericLogger("ExpressionFactorialGrammarAction");
	if (get_factor_type(factor) != INTEGER_TOKEN_TYPE) {
		LogError("Factorizacion entre tipos incompatibles");
		exit(1);
	}

	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = FACT_EXPRESSION;
	newExpression->left_expression = NULL;
	newExpression->right_expression = NULL;
	newExpression->factor_expression = factor;
	return newExpression;
}

Expression * ExpressionFactorGrammarAction(Factor * factor) {
	GenericLogger("ExpressionFactorGrammarAction");
	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = FACTOR_EXPRESSION;
	newExpression->left_expression = NULL;
	newExpression->right_expression = NULL;
	newExpression->factor_expression = factor;
	return newExpression;
}

If * IfGrammarAction(Condition * condition, Block * block, EndIf * end_if) {
	GenericLogger("IfGrammarAction");
	If * newIf = malloc(sizeof(If));
	newIf->condition = condition;
	newIf->block = block;
	newIf->end_if = end_if;
	return newIf;
}

EndIf * EndIfCloseBraceGrammarAction() {
	GenericLogger("EndIfCloseBraceGrammarAction");
	EndIf * newEndIf = malloc(sizeof(EndIf));
	newEndIf->type = CLOSE_NORMAL;
	newEndIf->block = NULL;
	return newEndIf;
}

EndIf * EndIfElseGrammarAction(Block * block) {
	GenericLogger("EndIfElseGrammarAction");	
	EndIf * newEndIf = malloc(sizeof(EndIf));
	newEndIf->type = CLOSE_BLOCK;
	newEndIf->block = block;
	return newEndIf;
}

Condition * ConditionGrammarAction(Factor * left_factor, CompareOpt * compare_opt, Factor * right_factor) {
	GenericLogger("ConditionGrammarAction");
	int LEFT_TYPE = get_factor_type(left_factor);
	int RIGHT_TYPE = get_factor_type(right_factor);
	if (LEFT_TYPE == LIST_TOKEN_TYPE || LEFT_TYPE == STRING_TOKEN_TYPE) {
		LogError("Comparacion entre tipos incompatibles");
		exit(1);
	}
	if (RIGHT_TYPE == LIST_TOKEN_TYPE || RIGHT_TYPE == STRING_TOKEN_TYPE) {
		LogError("Comparacion entre tipos incompatibles");
		exit(1);
	}
	Condition * newCondition = malloc(sizeof(Condition));
	newCondition->left_factor = left_factor;
	newCondition->compare_opt = compare_opt;
	newCondition->right_factor = right_factor;
	return newCondition;
}

Block * BlockGrammarAction(Instructions * instructions) {
	GenericLogger("BlockGrammarAction");
	Block * newBlock = malloc(sizeof(Block));
	newBlock->instructions = instructions;
	return newBlock;
}

CompareOpt * CompareEQGrammarAction(int comparator) {
	GenericLogger("CompareEQGrammarAction");
	CompareOpt * newCompareOpt = malloc(sizeof(CompareOpt));
	newCompareOpt->type = EQ_COMPARE;
	newCompareOpt->comparator = comparator;
	return newCompareOpt;
}

CompareOpt * CompareNEGrammarAction(int comparator) {
	GenericLogger("CompareNEGrammarAction");
	CompareOpt * newCompareOpt = malloc(sizeof(CompareOpt));
	newCompareOpt->type = NE_COMPARE;
	newCompareOpt->comparator = comparator;
	return newCompareOpt;
}

CompareOpt * CompareLEGrammarAction(int comparator) {
	GenericLogger("CompareLEGrammarAction");
	CompareOpt * newCompareOpt = malloc(sizeof(CompareOpt));
	newCompareOpt->type = LE_COMPARE;
	newCompareOpt->comparator = comparator;
	return newCompareOpt;
}

CompareOpt * CompareGEGrammarAction(int comparator) {
	GenericLogger("CompareGEGrammarAction");
	CompareOpt * newCompareOpt = malloc(sizeof(CompareOpt));
	newCompareOpt->type = GE_COMPARE;
	newCompareOpt->comparator = comparator;
	return newCompareOpt;
}

CompareOpt * CompareLTGrammarAction(int comparator) {
	GenericLogger("CompareLTGrammarAction");
	CompareOpt * newCompareOpt = malloc(sizeof(CompareOpt));
	newCompareOpt->type = LT_COMPARE;
	newCompareOpt->comparator = comparator;
	return newCompareOpt;
}

CompareOpt * CompareGTGrammarAction(int comparator) {
	GenericLogger("CompareGTGrammarAction");
	CompareOpt * newCompareOpt = malloc(sizeof(CompareOpt));
	newCompareOpt->type = GT_COMPARE;
	newCompareOpt->comparator = comparator;
	return newCompareOpt;
}

Declare * DeclareVariableGrammarAction(Token * token_type, char * variable_name, Expression * expression) {
	GenericLogger("DeclareVariableGrammarAction");
	Var * var = symbol_table_get(variable_name);
	if (var == NULL) {
		var = symbol_table_put(variable_name, token_type);
	} else {
		LogDebug("%s already existed, deleting it.", variable_name);
		symbol_table_remove(variable_name);
		var = symbol_table_put(variable_name, token_type);
	}

	if (token_type->type != get_expression_type(expression)) {
		LogError("Asignacion de tipos incorrectos");
		exit(1);
	}

	Declare * newDeclare = malloc(sizeof(Declare));
	newDeclare->type = EXPRESSION_DECLARE;
	newDeclare->token_type = token_type;
	newDeclare->variable_name = variable_name;
	newDeclare->dist_declare = NULL;
	newDeclare->expression = expression;
	newDeclare->input = NULL;
	return newDeclare;
}

Declare * DeclareDistributionGrammarAction(DistDeclare * dist_declare) {
	GenericLogger("DeclareDistributionGrammarAction");
	Token * newToken = malloc(sizeof(Token));
	newToken->type = FLOAT_TOKEN_TYPE;
	newToken->token = FLOAT;

	Var * var = symbol_table_get(dist_declare->variable_name);
	if (var == NULL) {
		var = symbol_table_put(dist_declare->variable_name, newToken);
	} else {
		LogDebug("%s already existed, deleting it.", dist_declare->variable_name);
		symbol_table_remove(dist_declare->variable_name);
		var = symbol_table_put(dist_declare->variable_name, newToken);
	}
	
	var->is_dist = true;
	var->dist_type = dist_declare->dist_type->type;
	Declare * newDeclare = malloc(sizeof(Declare));
	newDeclare->type = DIST_DECLARE;
	newDeclare->token_type = NULL;
	newDeclare->variable_name = NULL;
	newDeclare->dist_declare = dist_declare;
	newDeclare->expression = NULL;
	newDeclare->input = NULL;
	return newDeclare;
}

Declare * DeclareInputGrammarAction(Token * token_type, char * variable_name, Input * input) {
	GenericLogger("DeclareInputGrammarAction");
	if (token_type->type == LIST_TOKEN_TYPE) {
		LogError("Cant use input for list type");
		exit(1);
	}
	Var * var = symbol_table_get(variable_name);
	if (var == NULL) {
		var = symbol_table_put(variable_name, token_type);
	} else {
		LogDebug("%s already existed, deleting it.", variable_name);
		symbol_table_remove(variable_name);
		var = symbol_table_put(variable_name, token_type);
	}
	Declare * newDeclare = malloc(sizeof(Declare));
	newDeclare->type = INPUT_DECLARE;
	newDeclare->token_type = token_type;
	newDeclare->variable_name = variable_name;
	newDeclare->dist_declare = NULL;
	newDeclare->expression = NULL;
	newDeclare->input = input;
	return newDeclare;
}

Foreach * ForeachGrammarAction(List * list_value, ForeachFunctionArg * foreach_function_arg, int left_value, int right_value, int size) {
	GenericLogger("ForeachGrammarAction");
	if (size < 0) {
		LogError("El tamaño de la lista no puede ser negativo");
		exit(1);
	}
	if (left_value < 0) {
		LogError("Cota inferior no puede ser negativa");
		exit(1);
	}
	if (right_value < 0) {
		LogError("Cota superior no puede ser negativa");
		exit(1);
	}
	if (left_value < right_value) {
		LogError("[%d, %d] no es un rango valido", left_value, right_value);
		exit(1);
	}
	Foreach * newForeach = malloc(sizeof(Foreach));
	newForeach->type = LIST_FOREACH;
	newForeach->list_value = list_value;
	newForeach->foreach_function_arg = foreach_function_arg;
	newForeach->left_value = left_value;
	newForeach->right_value = right_value;
	newForeach->variable_name = NULL;
	newForeach->size = size;
	return newForeach;
}

Foreach * ForeachVariableGrammarAction(char * variable_name, ForeachFunctionArg * foreach_function_arg, int left_value, int right_value, int size) {
	GenericLogger("ForeachVariableGrammarAction");
	if (size < 0) {
		LogError("El tamaño de la lista no puede ser negativo");
		exit(1);
	}
	Var * var = symbol_table_get(variable_name);
	if (var == NULL) {
		LogError("%s no esta definida", variable_name);
		exit(1);
	}
	if (var->token_type->type != LIST_TOKEN_TYPE) {
		LogError("%s no es una lista", variable_name);
		exit(1);
	}
	Foreach * newForeach = malloc(sizeof(Foreach));
	newForeach->type = VARIABLE_FOREACH;
	newForeach->list_value = NULL;
	newForeach->foreach_function_arg = foreach_function_arg;
	newForeach->left_value = left_value;
	newForeach->right_value = right_value;
	newForeach->variable_name = variable_name;
	newForeach->size = size;
	return newForeach;
}

ForeachFunctionArg * ForeachFuncArgPrintGrammarAction(int function) {
	GenericLogger("ForeachFuncArgPrintGrammarAction");
	ForeachFunctionArg * newForeachFunctionArg = malloc(sizeof(ForeachFunctionArg));
	newForeachFunctionArg->type = PRINT_FOREACH;
	newForeachFunctionArg->function = function;
	return newForeachFunctionArg;
}

ForeachFunctionArg * ForeachFuncArgSqrtGrammarAction(int function) {
	GenericLogger("ForeachFuncArgSqrtGrammarAction");
	ForeachFunctionArg * newForeachFunctionArg = malloc(sizeof(ForeachFunctionArg));
	newForeachFunctionArg->type = SQRT_FOREACH;
	newForeachFunctionArg->function = function;
	return newForeachFunctionArg;
}

ForeachFunctionArg * ForeachFuncArgFactGrammarAction(int function) {
	GenericLogger("ForeachFuncArgFactGrammarAction");
	ForeachFunctionArg * newForeachFunctionArg = malloc(sizeof(ForeachFunctionArg));
	newForeachFunctionArg->type = FACT_FOREACH;
	newForeachFunctionArg->function = function;
	return newForeachFunctionArg;
}

ForeachFunctionArg * ForeachFuncArgAddGrammarAction(int function) {
	GenericLogger("ForeachFuncArgAddGrammarAction");
	ForeachFunctionArg * newForeachFunctionArg = malloc(sizeof(ForeachFunctionArg));
	newForeachFunctionArg->type = ADD_FOREACH;
	newForeachFunctionArg->function = function;
	return newForeachFunctionArg;
}

ForeachFunctionArg * ForeachFuncArgMulGrammarAction(int function) {
	GenericLogger("ForeachFuncArgMulGrammarAction");
	ForeachFunctionArg * newForeachFunctionArg = malloc(sizeof(ForeachFunctionArg));
	newForeachFunctionArg->type = MUL_FOREACH;
	newForeachFunctionArg->function = function;
	return newForeachFunctionArg;
}

Input * InputGrammarAction(int token) {
	GenericLogger("InputGrammarAction");
	Input * newInput = malloc(sizeof(Input));
	newInput->token = token;
	return newInput;
}

Print * PrintGrammarAction(Expression * expression) {
	GenericLogger("PrintGrammarAction");
	Print * newPrint = malloc(sizeof(Print));
	newPrint->expression = expression;
	return newPrint;
}

StatFunction * StatFunctionGrammarAction(StatFunctionType * stat_function_type, List * list_value, int size) {
	GenericLogger("StatFunctionGrammarAction");
	if (size < 0) {
		LogError("El tamaño de una lista no puede ser negativo");
		exit(1);
	}
	StatFunction * newStatFunction = malloc(sizeof(StatFunction));
	newStatFunction->type = LIST_STAT_FUNCTION;
	newStatFunction->stat_function_type = stat_function_type;
	newStatFunction->list_value = list_value;
	newStatFunction->variable_name = NULL;
	newStatFunction->size = size;
	return newStatFunction;
}

StatFunction * StatFunctionVariableGrammarAction(StatFunctionType * stat_function_type, char * variable_name, int size) {
	GenericLogger("StatFunctionVariableGrammarAction");
	if (size < 0) {
		LogError("El tamaño de una lista no puede ser negativo");
		exit(1);
	}
	Var * var = symbol_table_get(variable_name);
	LogDebug("1");
	if (var == NULL) {
		LogError("%s no esta definida", variable_name);
		exit(1);
	}
	if (var->token_type->type != LIST_TOKEN_TYPE) {
		LogError("%s no es una lista", variable_name);
		exit(1);
	}
	StatFunction * newStatFunction = malloc(sizeof(StatFunction));
	newStatFunction->type = VARIABLE_STAT_FUNCTION;
	newStatFunction->stat_function_type = stat_function_type;
	newStatFunction->list_value = NULL;
	newStatFunction->variable_name = variable_name;
	newStatFunction->size = size;
	return newStatFunction;
}

StatFunctionType * StatFunctionTypeMeanGrammarAction(int stat_function) { 
	GenericLogger("StatFunctionTypeMeanGrammarAction");
	StatFunctionType * newStatFunctionType = malloc(sizeof(StatFunctionType));
	newStatFunctionType->type = MEAN_STAT_TYPE;
	newStatFunctionType->stat_function = stat_function;
	return newStatFunctionType;
}

StatFunctionType * StatFunctionTypeModeGrammarAction(int stat_function) { 
	GenericLogger("StatFunctionTypeModeGrammarAction");
	StatFunctionType * newStatFunctionType = malloc(sizeof(StatFunctionType));
	newStatFunctionType->type = MODE_STAT_TYPE;
	newStatFunctionType->stat_function = stat_function;
	return newStatFunctionType;
}

StatFunctionType * StatFunctionTypeVarianceGrammarAction(int stat_function) { 
	GenericLogger("StatFunctionTypeVarianceGrammarAction");
	StatFunctionType * newStatFunctionType = malloc(sizeof(StatFunctionType));
	newStatFunctionType->type = VARIANCE_STAT_TYPE;
	newStatFunctionType->stat_function = stat_function;
	return newStatFunctionType;
}

StatFunctionType * StatFunctionTypeKurtosisGrammarAction(int stat_function) { 
	GenericLogger("StatFunctionTypeKurtosisGrammarAction");
	StatFunctionType * newStatFunctionType = malloc(sizeof(StatFunctionType));
	newStatFunctionType->type = KURTOSIS_STAT_TYPE;
	newStatFunctionType->stat_function = stat_function;
	return newStatFunctionType;
}

StatFunctionType * StatFunctionTypeQ1GrammarAction(int stat_function) { 
	GenericLogger("StatFunctionTypeQ1GrammarAction");
	StatFunctionType * newStatFunctionType = malloc(sizeof(StatFunctionType));
	newStatFunctionType->type = Q1_STAT_TYPE;
	newStatFunctionType->stat_function = stat_function;
	return newStatFunctionType;
}

StatFunctionType * StatFunctionTypeQ3GrammarAction(int stat_function) { 
	GenericLogger("StatFunctionTypeQ3GrammarAction");
	StatFunctionType * newStatFunctionType = malloc(sizeof(StatFunctionType));
	newStatFunctionType->type = Q3_STAT_TYPE;
	newStatFunctionType->stat_function = stat_function;
	return newStatFunctionType;
}

StatFunctionType * StatFunctionTypeMaxGrammarAction(int stat_function) { 
	GenericLogger("StatFunctionTypeMaxGrammarAction");
	StatFunctionType * newStatFunctionType = malloc(sizeof(StatFunctionType));
	newStatFunctionType->type = MAX_STAT_TYPE;
	newStatFunctionType->stat_function = stat_function;
	return newStatFunctionType;
}

StatFunctionType * StatFunctionTypeMinGrammarAction(int stat_function) { 
	GenericLogger("StatFunctionTypeMinGrammarAction");
	StatFunctionType * newStatFunctionType = malloc(sizeof(StatFunctionType));
	newStatFunctionType->type = MIN_STAT_TYPE;
	newStatFunctionType->stat_function = stat_function;
	return newStatFunctionType;
}

StatFunctionType * StatFunctionTypeSdGrammarAction(int stat_function) { 
	GenericLogger("StatFunctionTypeSdGrammarAction");
	StatFunctionType * newStatFunctionType = malloc(sizeof(StatFunctionType));
	newStatFunctionType->type = SD_STAT_TYPE;
	newStatFunctionType->stat_function = stat_function;
	return newStatFunctionType;
}

StatFunctionType * StatFunctionTypeSkewnessGrammarAction(int stat_function) { 
	GenericLogger("StatFunctionTypeSkewnessGrammarAction");
	StatFunctionType * newStatFunctionType = malloc(sizeof(StatFunctionType));
	newStatFunctionType->type = SKEWNESS_STAT_TYPE;
	newStatFunctionType->stat_function = stat_function;
	return newStatFunctionType;
}

Token * TypeIntegerGrammarAction(int token) {
	GenericLogger("TypeIntegerGrammarAction");
	Token * newToken = malloc(sizeof(Token));
	newToken->type = INTEGER_TOKEN_TYPE;
	newToken->token = token;
	return newToken;
}

Token * TypeFloatGrammarAction(int token) {
	GenericLogger("TypeFloatGrammarAction");
	Token * newToken = malloc(sizeof(Token));
	newToken->type = FLOAT_TOKEN_TYPE;
	newToken->token = token;
	return newToken;
}

Token * TypeStringGrammarAction(int token) {
	GenericLogger("TypeStringGrammarAction");
	Token * newToken = malloc(sizeof(Token));
	newToken->type = STRING_TOKEN_TYPE;
	newToken->token = token;
	return newToken;
}

Token * TypeListGrammarAction(int token) {
	GenericLogger("TypeListGrammarAction");
	Token * newToken = malloc(sizeof(Token));
	newToken->type = LIST_TOKEN_TYPE;
	newToken->token = token;
	return newToken;
}

DistDeclare * DistDeclareGrammarAction(DistType * dist_type, char * variable_name) {
	GenericLogger("DistDeclareGrammarAction");
	DistDeclare * newDistDeclare = malloc(sizeof(DistDeclare));
	newDistDeclare->dist_type = dist_type;
	newDistDeclare->variable_name = variable_name;
	return newDistDeclare;
}

DistType * DistTypeBinomialGrammarAction(Binomial * binomial) {
	GenericLogger("DistTypeBinomialGrammarAction");
	DistType * newDistType = malloc(sizeof(DistType));
	newDistType->type = BINOMIAL_TYPE;
	newDistType->binomial = binomial;
	newDistType->normal = NULL;
	newDistType->poisson = NULL;
	return newDistType;
}

DistType * DistTypeNormalGrammarAction(Normal * normal) {
	GenericLogger("DistTypeNormalGrammarAction");
	DistType * newDistType = malloc(sizeof(DistType));
	newDistType->type = NORMAL_TYPE;
	newDistType->binomial = NULL;
	newDistType->normal = normal;
	newDistType->poisson = NULL;
	return newDistType;
}

DistType * DistTypePoissonGrammarAction(Poisson * poisson) {
	GenericLogger("DistTypePoissonGrammarAction");
	DistType * newDistType = malloc(sizeof(DistType));
	newDistType->type = POISSON_TYPE;
	newDistType->binomial = NULL;
	newDistType->normal = NULL;
	newDistType->poisson = poisson;
	return newDistType;
}

Binomial * BinomialTypeValuesGrammarAction(int int_value, double float_value, int target) {
	GenericLogger("BinomialTypeValuesGrammarAction");
	Binomial * newBinomial = malloc(sizeof(Binomial));
	newBinomial->type = INTEGER_FLOAT_BINOMIAL;
	newBinomial->left_variable_name = NULL;
	newBinomial->right_variable_name = NULL;
	newBinomial->int_value = int_value;
	newBinomial->float_value = float_value;
	newBinomial->target = target;
	newBinomial->target_variable = NULL;
	return newBinomial;
}

Binomial * BinomialTypeVariablesGrammarAction(char * left_variable_name, char * right_variable_name, char * target_variable) {
	GenericLogger("BinomialTypeVariablesGrammarAction");
	Var * var1 = symbol_table_get(left_variable_name);
	if (var1 == NULL) {
		LogError("%s no esta definida", left_variable_name);
		exit(1);
	}
	if (var1->token_type->type != INTEGER_TOKEN_TYPE) {
		LogError("%s no es de tipo integer", left_variable_name);
		exit(1);
	}
	Var * var2 = symbol_table_get(right_variable_name);
	if (var2 == NULL) {
		LogError("%s no esta definida", right_variable_name);
		exit(1);
	}
	if (var2->token_type->type != FLOAT_TOKEN_TYPE) {
		LogError("%s no es de tipo float", right_variable_name);
		exit(1);
	}
	Var * var3 = symbol_table_get(target_variable);
	if (var3 == NULL) {
		LogError("%s no esta definida", target_variable);
		exit(1);
	}
	if (var3->token_type->type != INTEGER_TOKEN_TYPE) {
		LogError("%s no es de tipo integer", target_variable);
		exit(1);
	}
		
	Binomial * newBinomial = malloc(sizeof(Binomial));
	newBinomial->type = VARIABLE_VARIABLE_BINOMIAL;
	newBinomial->left_variable_name = left_variable_name;
	newBinomial->right_variable_name = right_variable_name;
	newBinomial->int_value = 0;
	newBinomial->float_value = 0;
	newBinomial->target = 0;
	newBinomial->target_variable = target_variable;
	return newBinomial;
}

Normal * NormalTypeValuesGrammarAction(double left_float, double right_float, double target) {
	GenericLogger("NormalTypeValuesGrammarAction");
	Normal * newNormal = malloc(sizeof(Normal));
	newNormal->type = FLOAT_FLOAT_NORMAL;
	newNormal->left_float = left_float;
	newNormal->right_float = right_float;
	newNormal->left_variable_name = NULL;
	newNormal->right_variable_name = NULL;
	newNormal->target = target;
	newNormal->target_variable = NULL;
	return newNormal;
}

Normal * NormalTypeVariableGrammarAction(char * left_variable_name, char * right_variable_name, char * target_variable) {
	GenericLogger("NormalTypeVariableGrammarAction");
	Var * var1 = symbol_table_get(left_variable_name);
	if (var1 == NULL) {
		LogError("%s no esta definida", left_variable_name);
		exit(1);
	}
	if (var1->token_type->type != FLOAT_TOKEN_TYPE) {
		LogError("%s no es de tipo float", left_variable_name);
		exit(1);
	}
	Var * var2 = symbol_table_get(right_variable_name);
	if (var2 == NULL) {
		LogError("%s no esta definida", right_variable_name);
		exit(1);
	}
	if (var2->token_type->type != FLOAT_TOKEN_TYPE) {
		LogError("%s no es de tipo float", right_variable_name);
		exit(1);
	}
	Var * var3 = symbol_table_get(target_variable);
	if (var3 == NULL) {
		LogError("%s no esta definida", target_variable);
		exit(1);
	}
	if (var3->token_type->type != FLOAT_TOKEN_TYPE) {
		LogError("%s no es de tipo float", target_variable);
		exit(1);
	}

	Normal * newNormal = malloc(sizeof(Normal));
	newNormal->type = VARIABLE_VARIABLE_NORMAL;
	newNormal->left_float = 0;
	newNormal->right_float = 0;
	newNormal->left_variable_name = left_variable_name;
	newNormal->right_variable_name = right_variable_name;
	newNormal->target = 0;
	newNormal->target_variable = target_variable;
	return newNormal;
}

Poisson * PoissonTypeValueGrammarAction(int int_value, int target) {
	GenericLogger("PoissonTypeValueGrammarAction");
	Poisson * newPoisson = malloc(sizeof(Poisson));
	newPoisson->type = INTEGER_POISSON;
	newPoisson->int_value = int_value;
	newPoisson->variable_name = NULL;
	newPoisson->target = target;
	newPoisson->target_variable = NULL;
	return newPoisson;
}

Poisson * PoissonTypeVariableGrammarAction(char * variable_name, char * target_variable) {
	GenericLogger("PoissonTypeVariableGrammarAction");
	Var * var1 = symbol_table_get(variable_name);
	if (var1 == NULL) {
		LogError("%s no esta definida", variable_name);
		exit(1);
	}
	if (var1->token_type->type != INTEGER_TOKEN_TYPE) {
		LogError("%s no es de tipo integer", variable_name);
		exit(1);
	}
	Var * var2 = symbol_table_get(target_variable);
	if (var2 == NULL) {
		LogError("%s no esta definida", target_variable);
		exit(1);
	}
	if (var2->token_type->type != INTEGER_TOKEN_TYPE) {
		LogError("%s no es de tipo integer", target_variable);
		exit(1);
	}
	Poisson * newPoisson = malloc(sizeof(Poisson));
	newPoisson->type = VARIABLE_POISSON;
	newPoisson->int_value = 0;
	newPoisson->variable_name = variable_name;
	newPoisson->target = 0;
	newPoisson->target_variable = target_variable;
	return newPoisson;
}

Factor * FactorExpressionGrammarAction(Expression * expression) {
	GenericLogger("FactorExpressionGrammarAction");
	Factor * newFactor = malloc(sizeof(Factor));
	newFactor->type = EXPRESSION_FACTOR;
	newFactor->expression = expression;
	newFactor->value = NULL;
	return newFactor;
}

Factor * FactorVariableGrammarAction(Value * value) {
	GenericLogger("FactorVariableGrammarAction");
	Factor * newFactor = malloc(sizeof(Factor));
	newFactor->type = VALUE_FACTOR;
	newFactor->expression = NULL;
	newFactor->value = value;
	return newFactor;
}

Value * ValueNumericGrammarAction(Numeric * numeric_value) {
	GenericLogger("ValueNumericGrammarAction");
	Value * newValue = malloc(sizeof(Value));
	newValue->type = NUMERIC_VALUE;
	newValue->numeric_value = numeric_value;
	newValue->text_value = NULL;
	newValue->list_value = NULL;
	newValue->variable_name = NULL;
	return newValue;
}

Value * ValueTextGrammarAction(Text * text_value) {
	GenericLogger("ValueTextGrammarAction");
	Value * newValue = malloc(sizeof(Value));
	newValue->type = TEXT_VALUE;
	newValue->numeric_value = NULL;
	newValue->text_value = text_value;
	newValue->list_value = NULL;
	newValue->variable_name = NULL;
	return newValue;
}

Value * ValueVariableGrammarAction(char * variable_name) {
	GenericLogger("ValueVariableGrammarAction");
	Var * var = symbol_table_get(variable_name);
	if (var == NULL) {
		LogError("%s no esta definida");
		exit(1);
	}
	Value * newValue = malloc(sizeof(Value));
	newValue->type = VARIABLE_VALUE;
	newValue->numeric_value = NULL;
	newValue->text_value = NULL;
	newValue->list_value = NULL;
	newValue->variable_name = variable_name;
	return newValue;
}

Value * ValueListGrammarAction(List * list_value) {
	GenericLogger("ValueListGrammarAction");
	Value * newValue = malloc(sizeof(Value));
	newValue->type = LIST_VALUE;
	newValue->numeric_value = NULL;
	newValue->text_value = NULL;
	newValue->list_value = list_value;
	newValue->variable_name = NULL;
	return newValue;
}

List * ListGrammarAction(ListArgs * list_args) {
	GenericLogger("ListGrammarAction");
	List * newList = malloc(sizeof(List));
	newList->list_args = list_args;
	return newList;
}

ListArgs * ListArgsRecGrammarAction(Expression * expression, ListArgs * list_args) {
	GenericLogger("ListArgsRecGrammarAction");
	ListArgs * newListArgs = malloc(sizeof(ListArgs));
	newListArgs->type = EXPRESSION_LIST_LISTARGS;
	newListArgs->expression = expression;
	newListArgs->list_args = list_args;
	return newListArgs;
}

ListArgs * ListArgsNumericGrammarAction(Expression * expression) {
	GenericLogger("ListArgsNumericGrammarAction");
	ListArgs * newListArgs = malloc(sizeof(ListArgs));
	newListArgs->type = EXPRESSION_LISTARGS;
	newListArgs->expression = expression;
	newListArgs->list_args = NULL;
	return newListArgs;
}

Numeric * NumericIntegerGrammarAction(int int_value) {
	GenericLogger("NumericIntegerGrammarAction");
	Numeric * newNumeric = malloc(sizeof(Numeric));
	newNumeric->type = INTEGER_NUMERIC;
	newNumeric->int_value = int_value;
	newNumeric->float_value = 0;
	newNumeric->stat_function = NULL;
	return newNumeric;
}

Numeric * NumericFloatGrammarAction(double float_value) {
	GenericLogger("NumericFloatGrammarAction");
	Numeric * newNumeric = malloc(sizeof(Numeric));
	newNumeric->type = FLOAT_NUMERIC;
	newNumeric->int_value = 0;
	newNumeric->float_value = float_value;
	newNumeric->stat_function = NULL;
	return newNumeric;
}

Numeric * NumericStatGrammarAction(StatFunction * stat_function) {
	GenericLogger("NumericStatGrammarAction");
	Numeric * newNumeric = malloc(sizeof(Numeric));
	newNumeric->type = STAT_NUMERIC;
	newNumeric->int_value = 0;
	newNumeric->float_value = 0;
	newNumeric->stat_function = stat_function;
	return newNumeric;
}

char * SymbolGrammarAction(char * variable_name) {
	LogDebug("SymbolGrammarAction");
	char * to_return = malloc(sizeof(char) * (yyleng + 1));
	strncpy(to_return, variable_name, yyleng);
	return to_return;
}

Text * TextGrammarAction(char * text_value) {
	GenericLogger("TextGrammarAction");
	Text * newText = malloc(sizeof(Text));
	newText->text_value = malloc(sizeof(char) * (yyleng + 1));
	strncpy(newText->text_value, text_value, yyleng);
	return newText;
}
