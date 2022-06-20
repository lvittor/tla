#include "../../backend/domain-specific/calculator.h"
#include "../../backend/support/logger.h"
#include "bison-actions.h"
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
	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = ADD_EXPRESSION;
	newExpression->left_expression = left_expression;
	newExpression->right_expression = right_expression;
	newExpression->factor_expression = NULL;
	return newExpression;
}

Expression * ExpressionSubtractionGrammarAction(Expression * left_expression, Expression * right_expression) {
	GenericLogger("ExpressionSubtractionGrammarAction");
	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = SUB_EXPRESSION;
	newExpression->left_expression = left_expression;
	newExpression->right_expression = right_expression;
	newExpression->factor_expression = NULL;
	return newExpression;
}

Expression * ExpressionMultiplicationGrammarAction(Expression * left_expression, Expression * right_expression) {
	GenericLogger("ExpressionMultiplicationGrammarAction");
	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = MUL_EXPRESSION;
	newExpression->left_expression = left_expression;
	newExpression->right_expression = right_expression;
	newExpression->factor_expression = NULL;
	return newExpression;
}

Expression * ExpressionDivisionGrammarAction(Expression * left_expression, Expression * right_expression) {
	GenericLogger("ExpressionDivisionGrammarAction");
	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = DIV_EXPRESSION;
	newExpression->left_expression = left_expression;
	newExpression->right_expression = right_expression;
	newExpression->factor_expression = NULL;
	return newExpression;
}

Expression * ExpressionPowerGrammarAction(Expression * left_expression, Expression * right_expression) {
	GenericLogger("ExpressionPowerGrammarAction");
	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = POW_EXPRESSION;
	newExpression->left_expression = left_expression;
	newExpression->right_expression = right_expression;
	newExpression->factor_expression = NULL;
	return newExpression;
}

Expression * ExpressionSqrtGrammarAction(Expression * expression) {
	GenericLogger("ExpressionSqrtGrammarAction");
	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = SQRT_EXPRESSION;
	newExpression->left_expression = expression;
	newExpression->right_expression = NULL;
	newExpression->factor_expression = NULL;
	return newExpression;
}

Expression * ExpressionFactorialGrammarAction(Factor * factor) {
	GenericLogger("ExpressionFactorialGrammarAction");
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

Declare * DeclareVariableGrammarAction(Token * type_token, char * variable_name, Expression * expression) {
	GenericLogger("DeclareVariableGrammarAction");
	Declare * newDeclare = malloc(sizeof(Declare));
	LogDebug("TOKEN TYPE: %d", type_token->type);
	newDeclare->type = EXPRESSION_DECLARE;
	newDeclare->type_token = type_token;
	newDeclare->variable_name = variable_name;
	newDeclare->dist_declare = NULL;
	newDeclare->expression = expression;
	newDeclare->input = NULL;
	return newDeclare;
}

Declare * DeclareDistributionGrammarAction(DistDeclare * dist_declare) {
	GenericLogger("DeclareDistributionGrammarAction");
	Declare * newDeclare = malloc(sizeof(Declare));
	newDeclare->type = DIST_DECLARE;
	newDeclare->type_token = NULL;
	newDeclare->variable_name = NULL;
	newDeclare->dist_declare = dist_declare;
	newDeclare->expression = NULL;
	newDeclare->input = NULL;
	return newDeclare;
}

Declare * DeclareInputGrammarAction(Token * type_token, char * variable_name, Input * input) {
	GenericLogger("DeclareInputGrammarAction");
	Declare * newDeclare = malloc(sizeof(Declare));
	newDeclare->type = INPUT_DECLARE;
	newDeclare->type_token = type_token;
	newDeclare->variable_name = variable_name;
	newDeclare->dist_declare = NULL;
	newDeclare->expression = NULL;
	newDeclare->input = input;
	return newDeclare;
}

Foreach * ForeachGrammarAction(List * list_value, ForeachFunctionArg * foreach_function_arg, int left_value, int right_value) {
	GenericLogger("ForeachGrammarAction");
	Foreach * newForeach = malloc(sizeof(Foreach));
	newForeach->list_value = list_value;
	newForeach->foreach_function_arg = foreach_function_arg;
	newForeach->left_value = left_value;
	newForeach->right_value = right_value;
	newForeach->variable_name = NULL;
	return newForeach;
}

Foreach * ForeachVariableGrammarAction(char * variable_name, ForeachFunctionArg * foreach_function_arg, int left_value, int right_value) {
	GenericLogger("ForeachVariableGrammarAction");
	Foreach * newForeach = malloc(sizeof(Foreach));
	newForeach->list_value = NULL;
	newForeach->foreach_function_arg = foreach_function_arg;
	newForeach->left_value = left_value;
	newForeach->right_value = right_value;
	newForeach->variable_name = variable_name;
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

// TODO: what should this do?
void InputGrammarAction() {
	GenericLogger("InputGrammarAction");
}

Print * PrintGrammarAction(Expression * expression) {
	GenericLogger("PrintGrammarAction");
	Print * newPrint = malloc(sizeof(Print));
	newPrint->expression = expression;
	return newPrint;
}

StatFunction * StatFunctionGrammarAction(StatFunctionType * stat_function_type, List * list_value) {
	GenericLogger("StatFunctionGrammarAction");
	StatFunction * newStatFunction = malloc(sizeof(StatFunction));
	newStatFunction->type = LIST_STAT_FUNCTION;
	newStatFunction->stat_function_type = stat_function_type;
	newStatFunction->list_value = list_value;
	newStatFunction->variable_name = NULL;
	return newStatFunction;
}

StatFunction * StatFunctionVariableGrammarAction(StatFunctionType * stat_function_type, char * variable_name) {
	GenericLogger("StatFunctionVariableGrammarAction");
	StatFunction * newStatFunction = malloc(sizeof(StatFunction));
	newStatFunction->type = VARIABLE_STAT_FUNCTION;
	newStatFunction->stat_function_type = stat_function_type;
	newStatFunction->list_value = NULL;
	newStatFunction->variable_name = variable_name;
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

Binomial * BinomialTypeValuesGrammarAction(int int_value, double float_value) {
	GenericLogger("BinomialTypeValuesGrammarAction");
	Binomial * newBinomial = malloc(sizeof(Binomial));
	newBinomial->type = INTEGER_FLOAT_BINOMIAL;
	newBinomial->left_variable_name = NULL;
	newBinomial->right_variable_name = NULL;
	newBinomial->int_value = int_value;
	newBinomial->float_value = float_value;
	return newBinomial;
}

Binomial * BinomialTypeVariablesGrammarAction(char * left_variable_name, char * right_variable_name) {
	GenericLogger("BinomialTypeVariablesGrammarAction");
	Binomial * newBinomial = malloc(sizeof(Binomial));
	newBinomial->type = INTEGER_FLOAT_BINOMIAL;
	newBinomial->left_variable_name = left_variable_name;
	newBinomial->right_variable_name = right_variable_name;
	newBinomial->int_value = 0;
	newBinomial->float_value = 0;
	return newBinomial;
}

Normal * NormalTypeValuesGrammarAction(double left_float, double right_float) {
	GenericLogger("NormalTypeValuesGrammarAction");
	Normal * newNormal = malloc(sizeof(Normal));
	newNormal->type = FLOAT_FLOAT_NORMAL;
	newNormal->left_float = left_float;
	newNormal->right_float = right_float;
	newNormal->left_variable_name = NULL;
	newNormal->right_variable_name = NULL;
	return newNormal;
}

Normal * NormalTypeVariableGrammarAction(char * left_variable_name, char * right_variable_name) {
	GenericLogger("NormalTypeVariableGrammarAction");
	Normal * newNormal = malloc(sizeof(Normal));
	newNormal->type = VARIABLE_VARIABLE_NORMAL;
	newNormal->left_float = 0;
	newNormal->right_float = 0;
	newNormal->left_variable_name = left_variable_name;
	newNormal->right_variable_name = right_variable_name;
	return newNormal;
}

Normal * NormalTypeSumGrammarAction(char * left_variable_name, char * right_variable_name)  {
	GenericLogger("NormalTypeSumGrammarAction");
	Normal * newNormal = malloc(sizeof(Normal));
	newNormal->type = VARIABLE_SUM_VARIABLE_NORMAL;
	newNormal->left_float = 0;
	newNormal->right_float = 0;
	newNormal->left_variable_name = left_variable_name;
	newNormal->right_variable_name = right_variable_name;
	return newNormal;
}

Poisson * PoissonTypeValueGrammarAction(int int_value) {
	GenericLogger("PoissonTypeValueGrammarAction");
	Poisson * newPoisson = malloc(sizeof(Poisson));
	newPoisson->type = INTEGER_POISSON;
	newPoisson->int_value = int_value;
	newPoisson->variable_name = NULL;
	return newPoisson;
}

Poisson * PoissonTypeVariableGrammarAction(char * variable_name) {
	GenericLogger("PoissonTypeVariableGrammarAction");
	Poisson * newPoisson = malloc(sizeof(Poisson));
	newPoisson->type = VARIABLE_POISSON;
	newPoisson->int_value = 0;
	newPoisson->variable_name = variable_name;
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

List * ListGrammarAction(char * list_value) {
	GenericLogger("ListGrammarAction");
	List * newList = malloc(sizeof(List));
	newList->list_value = list_value;
	return newList;
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
	LogDebug("SYMBOL GRAMMAR RECEIVED: [%s]", variable_name);
	char * to_return = malloc(sizeof(char) * (yyleng + 1));
	strncpy(to_return, variable_name, yyleng);
	LogDebug("SYMBOL_GRAMMAR HAS: [%s]", to_return);
	return to_return;
}

Text * TextGrammarAction(char * text_value) {
	GenericLogger("TextGrammarAction");
	Text * newText = malloc(sizeof(Text));
	LogDebug("TEXT GRAMMAR RECEIVED: [%s]", text_value);
	newText->text_value = malloc(sizeof(char) * (yyleng + 1));
	strncpy(newText->text_value, text_value, yyleng);
	LogDebug("TEXT GRAMMAR GOT: [%s]", newText->text_value);
	return newText;
}
