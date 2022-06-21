#ifndef __FREE_TREE_HEADER__
#define __FREE_TREE_HEADER__

#include "shared.h"
#include "logger.h"
#include <string.h>
#include <stdlib.h>


void free_main(Main * main);
void free_program(Program * program);
void free_instructions(Instructions * instuctions);
void free_instruction(Instruction * Instruction);
void free_statement(Statement * statement);
void free_if(If * if_instruction);
void free_endif(EndIf * end_if);
void free_condition(Condition * condition);
void free_block(Block * block);
void free_compareopt(CompareOpt * compare_opt);
void free_declare(Declare * declare);
void free_expression(Expression * expression);
void free_foreach(Foreach * foreach);
void free_foreach_arg(ForeachFunctionArg * foreach_function_arg);
void free_input(Input * input);
void free_print(Print * print);
void free_stat_function(StatFunction * stat_function);
void free_stat_function_type(StatFunctionType * stat_function_type);
void free_token(Token * token_type);
void free_dist_declare(DistDeclare * dist_declare);
void free_dist_type(DistType * dist_type);
void free_binomial(Binomial * binomial);
void free_normal(Normal * normal);
void free_poisson(Poisson * poisson);
void free_factor(Factor * factor);
void free_value(Value * value);
void free_list(List * list);
void free_list_args(ListArgs * list_args);
void free_numeric(Numeric * numeric);
void free_text(Text * text);

#endif