#ifndef GENERATOR_HEADER
#define GENERATOR_HEADER

#include "../support/shared.h"
#include "../../frontend/syntactic-analysis/bison-parser.h"

void GeneratorMain(Main * main, FILE * out);
void GeneratorProgram(Program * program, FILE * out);
void GeneratorInstructions(Instructions * instructions, FILE * out);
void GeneratorInstruction(Instruction * instruction, FILE * out);
void GeneratorStatement(Statement * statement, FILE * out);
void GeneratorIf(If * if_instruction, FILE * out);
void GeneratorCondition(Condition * condition, FILE * out);
void GeneratorBlock(Block * block, FILE * out);
void GeneratorEndIf(EndIf * end_if, FILE * out);
void GeneratorCompareOpt(CompareOpt * compare_opt, FILE * out);
void GeneratorFactor(Factor * factor, FILE * out);
void GeneratorValue(Value * value, FILE * out);
void GeneratorNumeric(Numeric * numeric, FILE * out);
void GeneratorDeclare(Declare * declare, FILE * out);
void GeneratorType(Token * type_token, FILE * out);
void GeneratorDistDeclare(DistDeclare * dist_declare, FILE * out);
void GeneratorDistType(DistType * dist_type, FILE * out);
void GeneratorBinomial(Binomial * binomial, FILE * out);
void GeneratorNormal(Normal * normal, FILE * out);
void GeneratorPoisson(Poisson * poisson, FILE * out);
void GeneratorExpression(Expression * expression, FILE * out);
void GeneratorPrint(Print * print_value, FILE * out);
void GeneratorForeach(Foreach * foreach, FILE * file);
void GeneratorForeachFunctionArgs(ForeachFunctionArg * foreach_function_arg, FILE * out);
void GeneratorStatFunction(StatFunction * stat_function, FILE * out);
void GeneratorStatFunctionType(StatFunctionType * stat_function_type, FILE * out);
void GeneratorList(List * list_value, FILE * out);
void GeneratorText(Text * text_value, FILE * out);
#endif
