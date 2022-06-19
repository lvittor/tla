#include "../../backend/domain-specific/calculator.h"
#include "../../backend/support/logger.h"
#include "bison-actions.h"
#include <stdio.h>
#include <string.h>

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

Program * ProgramGrammarAction(Instructions * instructions) {
    GenericLogger("programGrammarAction!");
    Program * newProgram = malloc(sizeof(Program));
	p->instructions = instructions;
	state.succeed = true;
	state.program = newProgram;
	return newProgram;
}

Instructions * InstructionsEOLGrammarAction(Instruction * instruction, Instructions * instructions) {
	GenericLogger("instructionsEOLGrammarAction");
	Instructions * newInstructions = malloc(sizeof(Instructions));
	newInstructions->type = EOL_INSTRUCTIONS;
	newInstructions->instruction = instruction;
	newInstructions->instructions = instructions;
	return newInstructions;
}

Instructions * InstructionsGrammarAction(Instruction * instruction) {
	GenericLogger("InstructionsGrammarAction");
	Instructions * newInstructions = malloc(sizeof(Instructions));
	newInstructions->type = INSTRUCTION_INSTRUCTIONS;
	newInstructions->instruction = instruction;
	newInstructions->instructions = NULL;
	return newInstructions;
}

Instruction * InstructionDeclareGrammarAction(Declare * declare_instruction) {
	GenericLogger("InstructionDeclareGrammarAction");
	Instruction * newInstruction = malloc(sizeof(Instruction));
	newInstruction->type = DECLARE_INSTRUCTION;
	newInstruction->declare_instruction = declare_instruction;
	newInstruction->print_instruction = NULL;
	newInstruction->if_instruction = NULL;
	newInstruction->foreach_instruction = NULL;
	return newInstruction;
}

Instruction * InstructionPrintGrammarAction(Print * print_instruction) {
	GenericLogger("InstructionPrintGrammarAction");
	Instruction * newInstruction = malloc(sizeof(Instruction));
	newInstruction->type = PRINT_INSTRUCTION;
	newInstruction->declare_instruction = NULL;
	newInstruction->print_instruction = print_instruction;
	newInstruction->if_instruction = NULL;
	newInstruction->foreach_instruction = NULL;
}

Instruction * InstructionIfGrammarAction(If * if_instruction) {
	GenericLogger("InstructionIfGrammarAction");
	Instruction * newInstruction = malloc(sizeof(Instruction));
	newInstruction->type = IF_INSTRUCTION;
	newInstruction->declare_instruction = NULL;
	newInstruction->print_instruction = NULL;
	newInstruction->if_instruction = if_instruction;
	newInstruction->foreach_instruction = NULL;
}

Instruction * InstructionForeachGrammarAction(Foreach * foreach_instruction) {
	GenericLogger("InstructionForeachGrammarAction");
	Instruction * newInstruction = malloc(sizeof(Instruction));
	newInstruction->type = FOREACH_INSTRUCTION;
	newInstruction->declare_instruction = NULL;
	newInstruction->print_instruction = NULL;
	newInstruction->if_instruction = NULL;
	newInstruction->foreach_instruction = foreach_instruction;
}

Expression * AdditionExpressionGrammarAction(Expression * left_expression, Expression * right_expression) {
	GenericLogger("AdditionExpressionGrammarAction");
	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = ADD_EXPRESSION;
	newExpression->left_expression = left_expression;
	newExpression->right_expression = right_expression;
	newExpression->factor_expression = NULL;
	return newExpression;
}

Expression * SubtractionExpressionGrammarAction(Expression * left_expression, Expression * right_expression) {
	GenericLogger("SubtractionExpressionGrammarAction");
	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = SUB_EXPRESSION;
	newExpression->left_expression = left_expression;
	newExpression->right_expression = right_expression;
	newExpression->factor_expression = NULL;
	return newExpression;
}

Expression * MultiplicationExpressionGrammarAction(Expression * left_expression, Expression * right_expression) {
	GenericLogger("MultiplicationExpressionGrammarAction");
	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = MUL_EXPRESSION;
	newExpression->left_expression = left_expression;
	newExpression->right_expression = right_expression;
	newExpression->factor_expression = NULL;
	return newExpression;
}

Expression * DivisionExpressionGrammarAction(Expression * left_expression, Expression * right_expression) {
	GenericLogger("DivisionExpressionGrammarAction");
	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = DIV_EXPRESSION;
	newExpression->left_expression = left_expression;
	newExpression->right_expression = right_expression;
	newExpression->factor_expression = NULL;
	return newExpression;
}

Expression * PowerExpressionGrammarAction(Expression * left_expression, Expression * right_expression) {
	GenericLogger("PowerExpressionGrammarAction");
	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = POW_EXPRESSION;
	newExpression->left_expression = left_expression;
	newExpression->right_expression = right_expression;
	newExpression->factor_expression = NULL;
	return newExpression;
}

Expression * SqrtExpressionGrammarAction(Expression * expression) {
	GenericLogger("SqrtExpressionGrammarAction");
	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = SQRT_EXPRESSION;
	newExpression->left_expression = expression;
	newExpression->right_expression = NULL;
	newExpression->factor_expression = NULL;
	return newExpression;
}

Expression * FactorialExpressionGrammarAction(Factor * factor) {
	GenericLogger("FactorialExpressionGrammarAction");
	Expression * newExpression = malloc(sizeof(Expression));
	newExpression->type = FACT_EXPRESSION;
	newExpression->left_expression = NULL;
	newExpression->right_expression = NULL;
	newExpression->factor_expression = factor;
	return newExpression;
}

Expression * FactorExpressionGrammarAction(Factor * factor) {
	GenericLogger("FactorExpressionGrammarAction");
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

Declare * DeclareVariableGrammarAction(Token * type_token, char * variable_name, Value * value) {
	GenericLogger("DeclareVariableGrammarAction");
	Declare * newDeclare = malloc(sizeof(Declare));
	newDeclare->type = VALUE_DECLARE;
	newDeclare->type_token = type_token;
	newDeclare->variable_name = variable_name;
	newDeclare->dist_declare = NULL;
	newDeclare->value = value;
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
	newDeclare->value = value;
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
	newDeclare->value = NULL;
	newDeclare->input = input;
	return newDeclare;
}

Foreach * ForeachGrammarAction(StatFunctionArg * stat_function_arg, ForeachFunctionArg foreach_function_arg, int left_value, int right_value) {
	GenericLogger("DeclareIForeachGrammarActionnputGrammarAction");
	Foreach * newForeach = malloc(sizeof(Foreach));
	newForeach->stat_function_arg = stat_function_arg;
	newForeach->foreach_function_arg = foreach_function_arg;
	newForeach->left_value = left_value;
	newForeach->right_value = right_value;
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

Print * PrintGrammarAction(PrintArgs * print_args) {
	GenericLogger("PrintGrammarAction");
	Print * newPrint = malloc(sizeof(Print));
	newPrint->print_args = print_args;
	return newPrint;
}

PrintArgs * PrintArgsTextAddGrammarAction(Text * text_value, PrintArgs * print_args) {
	GenericLogger("PrintArgsTextAdd");
	PrintArgs * newPrintArgs = malloc(sizeof(PrintArgs));
	newPrintArgs->type = TEXT_ADD_TYPE;
	newPrintArgs->text_value = text_value;
	newPrintArgs->print_args = print_args;
	newPrintArgs->expression = NULL;
	newPrintArgs->variable_name = NULL;
	return newPrintArgs;
}

PrintArgs * PrintArgsVariableAddGrammarAction(char * variable_name, PrintArgs * print_args) {
	GenericLogger("PrintArgsVariableAdd");
	PrintArgs * newPrintArgs = malloc(sizeof(PrintArgs));
	newPrintArgs->type = VAR_ADD_TYPE;
	newPrintArgs->text_value = NULL;
	newPrintArgs->print_args = print_args;
	newPrintArgs->expression = NULL;
	newPrintArgs->variable_name = variable_name;
	return newPrintArgs;
}

PrintArgs * PrintArgsExpressionAddGrammarAction(Expression * expression, PrintArgs * print_args) {
	GenericLogger("PrintArgsExpressionAdd");
	PrintArgs * newPrintArgs = malloc(sizeof(PrintArgs));
	newPrintArgs->type = EXPRESSION_ADD_TYPE;
	newPrintArgs->text_value = NULL;
	newPrintArgs->print_args = print_args;
	newPrintArgs->expression = expression;
	newPrintArgs->variable_name = NULL;
	return newPrintArgs;
}

PrintArgs * PrintArgsTextGrammarAction(Text * text_value) {
	GenericLogger("PrintArgsText");
	PrintArgs * newPrintArgs = malloc(sizeof(PrintArgs));
	newPrintArgs->type = TEXT_TYPE;
	newPrintArgs->text_value = text_value;
	newPrintArgs->print_args = NULL;
	newPrintArgs->expression = NULL;
	newPrintArgs->variable_name = NULL;
	return newPrintArgs;
}

PrintArgs * PrintArgsVariableGrammarAction(char * variable_name) {
	GenericLogger("PrintArgsVariable");
	PrintArgs * newPrintArgs = malloc(sizeof(PrintArgs));
	newPrintArgs->type = VAR_TYPE;
	newPrintArgs->text_value = NULL;
	newPrintArgs->print_args = NULL;
	newPrintArgs->expression = NULL;
	newPrintArgs->variable_name = variable_name;
	return newPrintArgs;
}

PrintArgs * PrintArgsExpressionGrammarAction(Expression * expression) {
	GenericLogger("PrintArgsExpression");
	PrintArgs * newPrintArgs = malloc(sizeof(PrintArgs));
	newPrintArgs->type = EXPRESSION_TYPE;
	newPrintArgs->text_value = NULL;
	newPrintArgs->print_args = NULL;
	newPrintArgs->expression = expression;
	newPrintArgs->variable_name = NULL;
	return newPrintArgs;
}

StatFunction * StatFunctionGrammarAction(StatFunctionType * stat_function_type, StatFunctionArg * stat_function_arg) {
	GenericLogger("StatFunctionGrammarAction");
	StatFunction * newStatFunction = malloc(sizeof(StatFunction));
	newStatFunction->stat_function_type = stat_function_type;
	newStatFunction->stat_function_arg = stat_function_arg;
	return newStatFunction;
}

StatFunctionArg * StatFunctionArgListGrammarAction(List * list_value) {
	GenericLogger("StatFunctionArgListGrammarAction");
	StatFunctionArg * newStatFunctionArg = malloc(sizeof(StatFunctionArg));
	newStatFunctionArg->type = LIST_STAT_ARG;
	newStatFunctionArg->list_value = list_value;
	newStatFunctionArg->variable_name = NULL;
	return newStatFunctionArg;
}

StatFunctionArg * StatFunctionArgVariableGrammarAction(char * variable_name) {
	GenericLogger("StatFunctionArgVariableGrammarAction");
	StatFunctionArg * newStatFunctionArg = malloc(sizeof(StatFunctionArg));
	newStatFunctionArg->type = VARIABLE_STAT_ARG;
	newStatFunctionArg->list_value = NULL;
	newStatFunctionArg->variable_name = variable_name;
	return newStatFunctionArg;
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
}

Token * TypeFloatGrammarAction(int token) {
	GenericLogger("TypeFloatGrammarAction");
	Token * newToken = malloc(sizeof(Token));
	newToken->type = FLOAT_TOKEN_TYPE;
	newToken->token = token;
}

Token * TypeStringGrammarAction(int token) {
	GenericLogger("TypeStringGrammarAction");
	Token * newToken = malloc(sizeof(Token));
	newToken->type = STRING_TOKEN_TYPE;
	newToken->token = token;
}

Token * TypeListGrammarAction(int token) {
	GenericLogger("TypeListGrammarAction");
	Token * newToken = malloc(sizeof(Token));
	newToken->type = LIST_TOKEN_TYPE;
	newToken->token = token;
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
	newDistType->binomial = binomial;
	newDistType->normal = NULL;
	newDistType->possion = NULL;
	return newDistType;
}

DistType * DistTypeNormalGrammarAction(Normal * normal) {
	GenericLogger("DistTypeNormalGrammarAction");
	DistType * newDistType = malloc(sizeof(DistType));
	newDistType->binomial = NULL;
	newDistType->normal = normal;
	newDistType->possion = NULL;
	return newDistType;
}

DistType * DistTypePoissonGrammarAction(Poisson * poisson) {
	GenericLogger("DistTypePoissonGrammarAction");
	DistType * newDistType = malloc(sizeof(DistType));
	newDistType->binomial = NULL;
	newDistType->normal = NULL;
	newDistType->possion = poisson;
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
	newBinomial->int_value = NULL;
	newBinomial->float_value = NULL;
	return newBinomial;
}

Normal * NormalTypeValuesGrammarAction(double left_float, double_right float) {
	GenericLogger("NormalTypeValuesGrammarAction");
	Normal * newNormal = malloc(sizeof(Normal));
	newNormal->type = FLOAT_FLOAT_NORMAL;
	newNormal->left_float = left_factor;
	newNormal->right_float = right_float;
	newNormal->left_variable_name = NULL;
	newNormal->right_variable_name = NULL;
	return newNormal;
}

Normal * NormalTypeVariableGrammarAction(char * left_variable_name, char * left_variable_name) {
	GenericLogger("NormalTypeVariableGrammarAction");
	Normal * newNormal = malloc(sizeof(Normal));
	newNormal->type = VARIABLE_VARIABLE_NORMAL;
	newNormal->left_float = NULL;
	newNormal->right_float = NULL;
	newNormal->left_variable_name = left_variable_name;
	newNormal->right_variable_name = right_variable_name;
	return newNormal;
}

Normal * NormalTypeSumGrammarAction(char * left_variable_name, char * left_variable_name)  {
	GenericLogger("NormalTypeSumGrammarAction");
	Normal * newNormal = malloc(sizeof(Normal));
	newNormal->type = VARIABLE_SUM_VARIABLE_NORMAL;
	newNormal->left_float = NULL;
	newNormal->right_float = NULL;
	newNormal->left_variable_name = left_variable_name;
	newNormal->right_variable_name = right_variable_name;
	return newNormal;
}

Poisson * PoissonTypeValueGrammarAction(int int_value) {
	GenericLogger("PoissonTypeValueGrammarAction")
	Poisson * newPossion = malloc(sizeof(Poisson));
	newPoisson->type = INTEGER_POISSON;
	newPoisson->int_value = int_value;
	newPoisson->variable_name = NULL;
	return newPoisson;
}

Poisson * PoissonTypeVariableGrammarAction(char * variable_name) {
	GenericLogger("PoissonTypeVariableGrammarAction")
	Poisson * newPossion = malloc(sizeof(Poisson));
	newPoisson->type = VARIABLE_POISSON;
	newPoisson->int_value = NULL;
	newPoisson->variable_name = variable_name;
	return newPoisson;
}

Factor * FactorExpressionGrammarAction(Expression * expression) {
	GenericLogger("FactorExpressionGrammarAction");
	Factor * newFactor = malloc(sizeof(newFactor));
	newFactor->type = EXPRESSION_FACTOR;
	newFactor->expression = expression;
	newFactor->numeric_value = NULL;
	newFactor->variable_name = NULL;
	return newFactor;
}

Factor * FactorValueGrammarAction(Numeric * numeric_value) {
	GenericLogger("FactorExpressionGrammarAction");
	Factor * newFactor = malloc(sizeof(newFactor));
	newFactor->type = NUMERIC_FACTOR;
	newFactor->expression = NULL;
	newFactor->numeric_value = numeric_value;
	newFactor->variable_name = NULL;
	return newFactor;
}

Factor * FactorVariableGrammarAction(char * variable_name) {
	GenericLogger("FactorExpressionGrammarAction");
	Factor * newFactor = malloc(sizeof(newFactor));
	newFactor->type = VARIABLE_FACTOR;
	newFactor->expression = NULL;
	newFactor->numeric_value = NULL;
	newFactor->variable_name = variable_name;
	return newFactor;
}

Value * ValueNumericGrammarAction(Numeric * numeric_value) {
	GenericLogger("ValueNumericGrammarAction");
	Value * newValue = malloc(sizeof(Value));
	newValue->type = NUMERIC_VALUE;
	newValue->numeric_value = numeric_value;
	newValue->text_value = NULL;
	newValue->list_value = NULL;
	newValue->expression = NULL;
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
	newValue->expression = NULL;
	newValue->variable_name = NULL;
	return newValue;
}

Value * ValueListGrammarAction(List * list_value){
	GenericLogger("ValueListGrammarAction");
	Value * newValue = malloc(sizeof(Value));
	newValue->type = LIST_VALUE;
	newValue->numeric_value = NULL;
	newValue->text_value = NULL;
	newValue->list_value = list_value;
	newValue->expression = NULL;
	newValue->variable_name = NULL;
	return newValue;
}

Value * ValueExpressionGrammarAction(Expression * expression){
	GenericLogger("ValueExpressionGrammarAction");
	Value * newValue = malloc(sizeof(Value));
	newValue->type = EXPRESSION_VALUE;
	newValue->numeric_value = NULL;
	newValue->text_value = NULL;
	newValue->list_value = NULL;
	newValue->expression = expression;
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
	newValue->expression = NULL;
	newValue->variable_name = variable_name;
	return newValue;
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

Text * TextGrammarAction(char * text_value) {
	GenericLogger("TextGrammarAction");
	Text * newText = malloc(sizeof(Text));
	newText->text_value = text_value;
	return newText;
}
