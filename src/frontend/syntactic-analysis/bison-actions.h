#ifndef BISON_ACTIONS_HEADER
#define BISON_ACTIONS_HEADER

#include "../../backend/support/shared.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GenericLogger(const char * string);

Program * ProgramGrammarAction(Instructions * instructions);
Instructions * InstructionsEOLGrammarAction(Instruction * instruction, Instructions * instructions);
Instructions * InstructionsGrammarAction(Instruction * instruction);
Instruction * InstructionDeclareGrammarAction(Declare * declare_instruction);
Instruction * InstructionPrintGrammarAction(Print * print_instruction);
Instruction * InstructionIfGrammarAction(If * if_instruction);
Instruction * InstructionForeachGrammarAction(Foreach * foreach_instruction);
Expression * AdditionExpressionGrammarAction(Expression * left_expression, Expression * right_expression);
Expression * SubtractionExpressionGrammarAction(Expression * left_expression, Expression * right_expression);
Expression * MultiplicationExpressionGrammarAction(Expression * left_expression, Expression * right_expression);
Expression * DivisionExpressionGrammarAction(Expression * left_expression, Expression * right_expression);
Expression * PowerExpressionGrammarAction(Expression * left_expression, Expression * right_expression);
Expression * FactorialExpressionGrammarAction(Factor * factor);
Expression * FactorExpressionGrammarAction(Factor * factor);
If * IfGrammarAction(Condition * condition, Block * block, EndIf * end_if);
EndIf * EndIfCloseBraceGrammarAction();
EndIf * EndIfElseGrammarAction(Block * block);
Condition * ConditionGrammarAction(Factor * left_factor, CompareOpt * compare_opt, Factor * right_factor);
Block * BlockGrammarAction(Instructions * instructions);
CompareOpt * CompareEQGrammarAction(int comparator);
CompareOpt * CompareNEGrammarAction(int comparator);
CompareOpt * CompareLEGrammarAction(int comparator);
CompareOpt * CompareGEGrammarAction(int comparator);
CompareOpt * CompareLTGrammarAction(int comparator);
CompareOpt * CompareGTGrammarAction(int comparator);
Declare * DeclareVariableGrammarAction(Token * type_token, char * variable_name, Value * value);
Declare * DeclareDistributionGrammarAction(DistDeclare * dist_declare); 
Declare * DeclareInputGrammarAction(Token * type_token, char * variable_name, Input * input);
Foreach * ForeachGrammarAction(StatFunctionArg * stat_function_arg, ForeachFunctionArg foreach_function_arg, int left_value, int right_value);
ForeachFunctionArg * ForeachFuncArgPrintGrammarAction(int function);
ForeachFunctionArg * ForeachFuncArgSqrtGrammarAction(int function);
ForeachFunctionArg * ForeachFuncArgFactGrammarAction(int function);
ForeachFunctionArg * ForeachFuncArgAddGrammarAction(int function);
ForeachFunctionArg * ForeachFuncArgMulGrammarAction(int function);
void InputGrammarAction();
Print * PrintGrammarAction(PrintArgs * print_args);
PrintArgs * PrintArgsTextAddGrammarAction(Text * text_value, PrintArgs * print_args);
PrintArgs * PrintArgsVariableAddGrammarAction(char * variable_name, PrintArgs * print_args);
PrintArgs * PrintArgsExpressionAddGrammarAction(Expression * expression, PrintArgs * print_args);
PrintArgs * PrintArgsTextGrammarAction(Text * text_value);
PrintArgs * PrintArgsVariableGrammarAction(char * variable_name);
PrintArgs * PrintArgsExpressionGrammarAction(Expression * expression);
StatFunction * StatFunctionGrammarAction(StatFunctionType * stat_function_type, StatFunctionArg * stat_function_arg);
StatFunctionArg * StatFunctionArgListGrammarAction(List * list_value);
StatFunctionArg * StatFunctionArgVariableGrammarAction(char * variable_name);
StatFunctionType * StatFunctionTypeMeanGrammarAction(int stat_function);
StatFunctionType * StatFunctionTypeModeGrammarAction(int stat_function);
StatFunctionType * StatFunctionTypeVarianceGrammarAction(int stat_function);
StatFunctionType * StatFunctionTypeKurtosisGrammarAction(int stat_function);
StatFunctionType * StatFunctionTypeQ1GrammarAction(int stat_function);
StatFunctionType * StatFunctionTypeQ3GrammarAction(int stat_function);
StatFunctionType * StatFunctionTypeMaxGrammarAction(int stat_function);
StatFunctionType * StatFunctionTypeMinGrammarAction(int stat_function);
StatFunctionType * StatFunctionTypeSdGrammarAction(int stat_function);
StatFunctionType * StatFunctionTypeSkewnessGrammarAction(int stat_function);
Token * TypeIntegerGrammarAction(int token);
Token * TypeFloatGrammarAction(int token);
Token * TypeStringGrammarAction(int token);
Token * TypeListGrammarAction(int token);
DistDeclare * DistDeclareGrammarAction(DistType * dist_type, char * variable_name);
DistType * DistTypeBinomialGrammarAction(Binomial * binomial);
DistType * DistTypeNormalGrammarAction(Normal * normal);
DistType * DistTypePoissonGrammarAction(Poisson * poisson);
Binomial * BinomialTypeValuesGrammarAction(int int_value, double float_value);
Binomial * BinomialTypeVariablesGrammarAction(char * left_variable_name, char * right_variable_name);
Normal * NormalTypeValuesGrammarAction(double left_float, double_right float);
Normal * NormalTypeVariableGrammarAction(char * left_variable_name, char * left_variable_name);
Normal * NormalTypeSumGrammarAction(char * left_variable_name, char * left_variable_name);
Poisson * PoissonTypeValueGrammarAction(int int_value);
Poisson * PoissonTypeVariableGrammarAction(char * variable_name);
Factor * FactorExpressionGrammarAction(Expression * expression);
Factor * FactorValueGrammarAction(Numeric * numeric_value);
Factor * FactorVariableGrammarAction(char * variable_name);
Value * ValueNumericGrammarAction(Numeric * numeric_value);
Value * ValueTextGrammarAction(Text * text_value);
Value * ValueListGrammarAction(List * list_value){;
Value * ValueExpressionGrammarAction(Expression * expression);
Value * ValueVariableGrammarAction(char * variable_name);
Numeric * NumericIntegerGrammarAction(int int_value);
Numeric * NumericFloatGrammarAction(double float_value);
Numeric * NumericStatGrammarAction(StatFunction * stat_function);
Text * TextGrammarAction(char * text_value);

#endif
