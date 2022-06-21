#ifndef BISON_ACTIONS_HEADER
#define BISON_ACTIONS_HEADER

#include "../../backend/support/shared.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GenericLogger(const char * string);

Main * MainGrammarAction(Program * program);
Program * ProgramGrammarAction(Instructions * instructions);
Instructions * InstructionsGrammarAction(Instruction * instruction, Instructions * instructions);
Instructions * InstructionOneGrammarAction(Instruction * instruction);
Instruction * InstructionStatementGrammarAction(Statement * statement_instruction);
Instruction * InstructionIfGrammarAction(If * if_instruction);
Statement * StatementDeclareGrammarAction(Declare * declare_statement);
Statement * StatementPrintGrammarAction(Print * print_statement);
Statement * StatementForeachGrammarAction(Foreach * foreach_statement);
Expression * ExpressionAdditionGrammarAction(Expression * left_expression, Expression * right_expression);
Expression * ExpressionSubtractionGrammarAction(Expression * left_expression, Expression * right_expression);
Expression * ExpressionMultiplicationGrammarAction(Expression * left_expression, Expression * right_expression);
Expression * ExpressionDivisionGrammarAction(Expression * left_expression, Expression * right_expression);
Expression * ExpressionPowerGrammarAction(Expression * left_expression, Expression * right_expression);
Expression * ExpressionSqrtGrammarAction(Expression * expression);
Expression * ExpressionFactorialGrammarAction(Factor * factor);
Expression * ExpressionFactorGrammarAction(Factor * factor);
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
Declare * DeclareVariableGrammarAction(Token * token_type, char * variable_name, Expression * expression);
Declare * DeclareDistributionGrammarAction(DistDeclare * dist_declare); 
Declare * DeclareInputGrammarAction(Token * token_type, char * variable_name, Input * input);
Foreach * ForeachGrammarAction(List * list_value, ForeachFunctionArg * foreach_function_arg, int left_value, int right_value);
Foreach * ForeachVariableGrammarAction(char * variable_name, ForeachFunctionArg * foreach_function_arg, int left_value, int right_value);
ForeachFunctionArg * ForeachFuncArgPrintGrammarAction(int function);
ForeachFunctionArg * ForeachFuncArgSqrtGrammarAction(int function);
ForeachFunctionArg * ForeachFuncArgFactGrammarAction(int function);
ForeachFunctionArg * ForeachFuncArgAddGrammarAction(int function);
ForeachFunctionArg * ForeachFuncArgMulGrammarAction(int function);
Input * InputGrammarAction(int token);
Print * PrintGrammarAction(Expression * expression);
StatFunction * StatFunctionGrammarAction(StatFunctionType * stat_function_type, List * list_value);
StatFunction * StatFunctionVariableGrammarAction(StatFunctionType * stat_function_type, char * variable_name);
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
Binomial * BinomialTypeValuesGrammarAction(int int_value, double float_value, int target);
Binomial * BinomialTypeVariablesGrammarAction(char * left_variable_name, char * right_variable_name, char * target_variable);
Normal * NormalTypeValuesGrammarAction(double left_float, double right_float, double target);
Normal * NormalTypeVariableGrammarAction(char * left_variable_name, char * right_variable_name, char * target_variable);
Normal * NormalTypeSumGrammarAction(char * left_variable_name, char * right_variable_name, char * target_variable);
Poisson * PoissonTypeValueGrammarAction(int int_value, int target);
Poisson * PoissonTypeVariableGrammarAction(char * variable_name, char * target_variable);
Factor * FactorExpressionGrammarAction(Expression * expression);
Factor * FactorVariableGrammarAction(Value * value);
Value * ValueNumericGrammarAction(Numeric * numeric_value);
Value * ValueTextGrammarAction(Text * text_value);
Value * ValueVariableGrammarAction(char * variable_name);
Value * ValueListGrammarAction(List * list_value);
List * ListGrammarAction(ListArgs * list_args);
ListArgs * ListArgsRecGrammarAction(Expression * expression, ListArgs * list_args);
ListArgs * ListArgsNumericGrammarAction(Expression * expression);
Numeric * NumericIntegerGrammarAction(int int_value);
Numeric * NumericFloatGrammarAction(double float_value);
Numeric * NumericStatGrammarAction(StatFunction * stat_function);
char * SymbolGrammarAction(char * variable_name);
Text * TextGrammarAction(char * text_value);

#endif
