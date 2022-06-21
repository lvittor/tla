#include "free-tree.h"

void free_main(Main * main) {
    if (main == NULL)
        return;
    LogDebug("Free of main");
    free_program(main->program);
    free(main);
}

void free_program(Program * program) {
    if (program == NULL)
        return;
    LogDebug("Free of program");
    free_instructions(program->instructions);
    free(program);
}

void free_instructions(Instructions * instructions) {
    if (instructions == NULL)
        return;
    LogDebug("Free of instructions");
    free_instruction(instructions->instruction);
    free_instructions(instructions->instructions);
    free(instructions);
}

void free_instruction(Instruction * instruction) {
    if (instruction == NULL)
        return;
    LogDebug("Free of instruction");
    free_statement(instruction->statement_instruction);
    free_if(instruction->if_instruction);
    free(instruction);
}

void free_statement(Statement * statement) {
    if (statement == NULL)
        return;
    LogDebug("Free of statement");
    free_declare(statement->declare_statement);
    free_print(statement->print_statement);
    free_foreach(statement->foreach_statement);
    free(statement);
}

void free_if(If * if_instruction) {
    if (if_instruction == NULL)
        return;
    LogDebug("Free of if");
    free_condition(if_instruction->condition);
    free_block(if_instruction->block);
    free_endif(if_instruction->end_if);
    free(if_instruction);
}

void free_endif(EndIf * end_if) {
    if (end_if == NULL)
        return;
    LogDebug("Free of end_if");
    free_block(end_if->block);
    free(end_if);
}

void free_condition(Condition * condition) {
    if (condition == NULL)
        return;
    LogDebug("Free of condition");
    free_factor(condition->left_factor);
    free_factor(condition->right_factor);
    free_compareopt(condition->compare_opt);
    free(condition);
}

void free_block(Block * block) {
    if (block == NULL)
        return;
    LogDebug("Free of block");
    free_instructions(block->instructions);
    free(block);
}

void free_compareopt(CompareOpt * compare_opt) {
    if (compare_opt == NULL)
        return;
    LogDebug("Free of compareopt");
    free(compare_opt);
}

void free_declare(Declare * declare) {
    if (declare == NULL)
        return;
    LogDebug("Free of declare");
    free_token(declare->token_type);
    free(declare->variable_name);
    free_dist_declare(declare->dist_declare);
    free_expression(declare->expression);
    free_input(declare->input);
    free(declare);
}

void free_expression(Expression * expression) {
    if (expression == NULL)
        return;
    LogDebug("Free of expression");
    free_expression(expression->left_expression);
    free_expression(expression->right_expression);
    free_factor(expression->factor_expression);
    free(expression);
}

void free_foreach(Foreach * foreach) {
    if (foreach == NULL)
        return;
    LogDebug("Free of foreach");
    free_list(foreach->list_value);
    free_foreach_arg(foreach->foreach_function_arg);
    free(foreach->variable_name);
    free(foreach);
}

void free_foreach_arg(ForeachFunctionArg * foreach_function_arg) {
    if (foreach_function_arg == NULL)
        return;
    LogDebug("Free of foreach_arg");
    free(foreach_function_arg);
}

void free_input(Input * input) {
    if (input == NULL)
        return;
    LogDebug("Free of input");
    free(input);
}

void free_print(Print * print) {
    if (print == NULL)
        return;
    LogDebug("Free of print");
    free_expression(print->expression);
    free(print);
}

void free_stat_function(StatFunction * stat_function) {
    if (stat_function == NULL)
        return;
    LogDebug("Free of stat_function");
    free_stat_function_type(stat_function->stat_function_type);
    free_list(stat_function->list_value);
    free(stat_function->variable_name);
    free(stat_function);
}

void free_stat_function_type(StatFunctionType * stat_function_type) {
    if (stat_function_type == NULL)
        return;
    LogDebug("Free of stat_function_type");
    free(stat_function_type);
}

void free_token(Token * token_type) {
    if (token_type == NULL)
        return;
    LogDebug("Free of token");
    free(token_type);
}

void free_dist_declare(DistDeclare * dist_declare) {
    if (dist_declare == NULL)
        return;
    LogDebug("Free of dist_declare");
    free_dist_type(dist_declare->dist_type);
    free(dist_declare->variable_name);
    free(dist_declare);
}

void free_dist_type(DistType * dist_type) {
    if (dist_type == NULL)
        return;
    LogDebug("Free of dist_type");
    free_binomial(dist_type->binomial);
    free_normal(dist_type->normal);
    free_poisson(dist_type->poisson);
    free(dist_type);
}

void free_binomial(Binomial * binomial) {
    if (binomial == NULL)
        return;
    LogDebug("Free of binomial");
    free(binomial->left_variable_name);
    free(binomial->right_variable_name);
    free(binomial->target_variable);
    free(binomial);
}

void free_normal(Normal * normal) {
    if (normal == NULL)
        return;
    LogDebug("Free of normal");
    free(normal->left_variable_name);
    free(normal->right_variable_name);
    free(normal->target_variable);
    free(normal);
}

void free_poisson(Poisson * poisson) {
    if (poisson == NULL)
        return;
    LogDebug("Free of poisson");
    free(poisson->variable_name);
    free(poisson->target_variable);
    free(poisson);
}

void free_factor(Factor * factor) {
    if (factor == NULL)
        return;
    LogDebug("Free of factor");
    free_expression(factor->expression);
    free_value(factor->value);
    free(factor);
}

void free_value(Value * value) {
    if (value == NULL)
        return;
    LogDebug("Free of value");
    free_numeric(value->numeric_value);
    free_text(value->text_value);
    free_list(value->list_value);
    free(value->variable_name);
    free(value);
}

void free_list(List * list) {
    if (list == NULL)
        return;
    LogDebug("Free of list");
    free_list_args(list->list_args);
    free(list);
}

void free_list_args(ListArgs * list_args) {
    if (list_args == NULL)
        return;
    LogDebug("Free of list_args");
    free_expression(list_args->expression);
    free_list_args(list_args->list_args);
    free(list_args);
}

void free_numeric(Numeric * numeric) {
    if (numeric == NULL)
        return;
    LogDebug("Free of numeric");
    free_stat_function(numeric->stat_function);
    free(numeric);
}

void free_text(Text * text) {
    if (text == NULL)
        return;
    LogDebug("Free of text");
    free(text->text_value);
}
