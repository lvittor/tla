#include "../support/logger.h"
#include "generator.h"
#include "../support/get-types.h"

/**
 * Implementación de "generator.h".
 */

// LogDebug("Generating..");

static int current_indent = 0;

void GeneratorMain(Main * main, FILE * out) {
	LogDebug("Generating main..");
	fprintf(out, "#include <stdio.h>\n");
	fprintf(out, "#include <stdlib.h>\n");
	fprintf(out, "#include \"../src/backend/domain-specific/input-reader.h\"\n");
	fprintf(out, "#include \"../src/backend/domain-specific/stat-functions.h\"\n\n");
	fprintf(out, "int main() {\n");
	current_indent++;
	GeneratorProgram(main->program, out);
	fprintf(out, "\treturn 0;\n");
	fprintf(out, "}");
}

void GeneratorProgram(Program * program, FILE * out) {
	LogDebug("Generating program..");
	GeneratorInstructions(program->instructions, out);
}

void GeneratorInstructions(Instructions * instructions, FILE * out) {
	LogDebug("Generating instructions..");
	switch (instructions->type) {
		case INSTRUCTION_INSTRUCTIONS:
			GeneratorInstruction(instructions->instruction, out);
			GeneratorInstructions(instructions->instructions, out);
			break;
		case ONE_INSTRUCTIONS:
			GeneratorInstruction(instructions->instruction, out);
			break;
		default:
			LogInfo("Instructions type not found");
			break;
	}
}

void GeneratorInstruction(Instruction * instruction, FILE * out) {
	LogDebug("Generating instruction..");
	for (int i = 0; i < current_indent; i++)
		fprintf(out, "\t");
	switch (instruction->type) {
		case STATEMENT_INSTRUCTION:
			GeneratorStatement(instruction->statement_instruction, out);
			fprintf(out, ";\n");
			break;
		case IF_INSTRUCTION:
			GeneratorIf(instruction->if_instruction, out);
			break;
		default:
			LogInfo("Instruction type not found");
			break;
	}
}

void GeneratorStatement(Statement * statement, FILE * out) {
	LogDebug("Generating statement..");
	switch (statement->type) {
		case PRINT_STATEMENT:
			GeneratorPrint(statement->print_statement, out);
			break;
		case DECLARE_STATEMENT:
			GeneratorDeclare(statement->declare_statement, out);
			break;
		case FOREACH_STATEMENT:
			GeneratorForeach(statement->foreach_statement, out);
			break;
		default:
			LogInfo("Statement type not found");
			break;
	}
}

void GeneratorIf(If * if_instruction, FILE * out) {
	LogDebug("Generating if..");
	fprintf(out, "if ");
	GeneratorCondition(if_instruction->condition, out);
	fprintf(out, " {\n");
	current_indent++;
	GeneratorBlock(if_instruction->block, out);
	GeneratorEndIf(if_instruction->end_if, out);
}

void GeneratorCondition(Condition * condition, FILE * out) {
	LogDebug("Generating condition..");
	fprintf(out, "(");
	GeneratorFactor(condition->left_factor, out);
	GeneratorCompareOpt(condition->compare_opt, out);
	GeneratorFactor(condition->right_factor, out);
	fprintf(out, ")");
}

void GeneratorBlock(Block * block, FILE * out) {
	LogDebug("Generating block..");
	GeneratorInstructions(block->instructions, out); // kinda useless, could delete blocks
}

void GeneratorEndIf(EndIf * end_if, FILE * out) {
	LogDebug("Generating end_if..");
	for (int i = 0; i < current_indent - 1; i++)
		fprintf(out, "\t");
	switch (end_if->type) {
		case CLOSE_NORMAL:
			fprintf(out, "}\n");
			current_indent--;
			break;
		case CLOSE_BLOCK:
			fprintf(out, "} else {\n");
			GeneratorBlock(end_if->block, out);
			for (int i = 0; i < current_indent - 1; i++)
				fprintf(out, "\t");
			fprintf(out, "}\n");
			current_indent--;
			break;
		default:
			LogInfo("EndIf type not found");
			break;
	}
}

void GeneratorCompareOpt(CompareOpt * compare_opt, FILE * out) {
	LogDebug("Generating compare opt..");
	switch (compare_opt->type) {
		case EQ_COMPARE:
			fprintf(out, " == ");
			break;
		case NE_COMPARE:
			fprintf(out, " != ");
			break;
		case LE_COMPARE:
			fprintf(out, " <= ");
			break;
		case GE_COMPARE:
			fprintf(out, " >= ");
			break;
		case LT_COMPARE:
			fprintf(out, " < ");
			break;
		case GT_COMPARE:
			fprintf(out, " > ");
			break;
		default:
			LogInfo("CompareOpt type not found");
			break;
	}
}

void GeneratorFactor(Factor * factor, FILE * out) {
	LogDebug("Generating factor..");
	switch (factor->type) {
		case EXPRESSION_FACTOR:
			fprintf(out, "(");
			GeneratorExpression(factor->expression, out);
			fprintf(out, ")");
			break;
		case VALUE_FACTOR:
			GeneratorValue(factor->value, out);
			break;
		default:
			LogInfo("Factor type not found");
			break;
	}
}

void GeneratorValue(Value * value, FILE * out) {
	LogDebug("Generating value..");
	switch (value->type) {
		case NUMERIC_VALUE:
			GeneratorNumeric(value->numeric_value, out);
			break;
		case TEXT_VALUE:
			GeneratorText(value->text_value, out);
			break;
		case LIST_VALUE:
			GeneratorList(value->list_value, out);
			break;
		case VARIABLE_VALUE:
			fprintf(out, "%s", value->variable_name);
			break;
		default:
			LogInfo("Value type not found");
			break;
	}
}

void GeneratorNumeric(Numeric * numeric, FILE * out) {
	LogDebug("Generating numeric..");
	switch (numeric->type) {
		case INTEGER_NUMERIC:
			fprintf(out, "%d", numeric->int_value);
			break;
		case FLOAT_NUMERIC:
			fprintf(out, "%f", numeric->float_value);
			break;
		case STAT_NUMERIC:
			GeneratorStatFunction(numeric->stat_function, out);
			break;
		default:
			LogInfo("Numeric type not found");
			break;
	}
}

void GeneratorDeclare(Declare * declare, FILE * out) {
	LogDebug("Generating declare..");
	switch (declare->type) {
		case EXPRESSION_DECLARE:
			GeneratorType(declare->token_type, out);
			if (declare->token_type->type == LIST_TOKEN_TYPE) {
				fprintf(out, "%s[] = ", declare->variable_name);
			} else {
				fprintf(out, "%s = ", declare->variable_name);
			}
			GeneratorExpression(declare->expression, out);
			break;
		case DIST_DECLARE:
			GeneratorDistDeclare(declare->dist_declare, out);
			break;
		case INPUT_DECLARE:
			GeneratorType(declare->token_type, out);
			switch (declare->token_type->type) {
				case INTEGER_TOKEN_TYPE:
					fprintf(out, "%s = input_int()", declare->variable_name);
					break;
				case FLOAT_TOKEN_TYPE:
					fprintf(out, "%s = input_float()", declare->variable_name);
					break;
				case STRING_TOKEN_TYPE:
					fprintf(out, "%s = input_string()", declare->variable_name);
					break;
				default:
					LogInfo("Token type not found");
					break;
			}
			break;
		default:
			LogInfo("Declare type not found");
			break;
	}
}

void GeneratorType(Token * token_type, FILE * out) {
	LogDebug("Generating type..");
	switch (token_type->type) {
		case INTEGER_TOKEN_TYPE:
			fprintf(out, "int ");
			break;
		case FLOAT_TOKEN_TYPE:
			fprintf(out, "double ");
			break;
		case STRING_TOKEN_TYPE:
			fprintf(out, "char * ");
			break;
		case LIST_TOKEN_TYPE:
			fprintf(out, "double ");
			break;
		default:
			LogInfo("Type type not found");
			break;
	}
}

void GeneratorDistDeclare(DistDeclare * dist_declare, FILE * out) {
	LogDebug("Generating dist declare..");
	fprintf(out, "double %s = ", dist_declare->variable_name);
	GeneratorDistType(dist_declare->dist_type, out);
}

void GeneratorDistType(DistType * dist_type, FILE * out) {
	LogDebug("Generating dist type..");
	switch (dist_type->type) {
		case BINOMIAL_TYPE:
			GeneratorBinomial(dist_type->binomial, out);
			break;
		case NORMAL_TYPE:
			GeneratorNormal(dist_type->normal, out);
			break;
		case POISSON_TYPE:
			GeneratorPoisson(dist_type->poisson, out);
			break;
		default:
			LogInfo("DistType type not found");
			break;
	}
}

void GeneratorBinomial(Binomial * binomial, FILE * out) {
	LogDebug("Generating binomial..");
	fprintf(out, "binomial(");
	switch (binomial->type) {
		case INTEGER_FLOAT_BINOMIAL:
			fprintf(out, "%d, %f, %d", binomial->int_value, binomial->float_value, binomial->target);
			break;
		case VARIABLE_VARIABLE_BINOMIAL:
			fprintf(out, "%s, %s, %s", binomial->left_variable_name, binomial->right_variable_name, binomial->target_variable);
			break;
		default:
			LogInfo("Binomial type not found");
			break;
	}
	fprintf(out, ")");
}

void GeneratorNormal(Normal * normal, FILE * out) {
	LogDebug("Generating normal..");
	fprintf(out, "normal(");
	switch (normal->type) {
		case FLOAT_FLOAT_NORMAL:
			fprintf(out, "%f, %f, %f", normal->left_float, normal->right_float, normal->target);
			break;
		case VARIABLE_VARIABLE_NORMAL:
			fprintf(out, "%s, %s, %s", normal->left_variable_name, normal->right_variable_name, normal->target_variable);
			break;
		default:
			LogInfo("Normal type not found");
			break;
	}
	fprintf(out, ")");
}

void GeneratorPoisson(Poisson * poisson, FILE * out) {
	LogDebug("Generating poisson..");
	fprintf(out, "poisson(");
	switch (poisson->type) {
		case INTEGER_POISSON:
			fprintf(out, "%d, %d", poisson->int_value, poisson->target);
			break;
		case VARIABLE_POISSON:
			fprintf(out, "%s, %s", poisson->variable_name, poisson->target_variable);
			break;
		default:
			LogInfo("Poisson type not found");
			break;
	}
	fprintf(out, ")");
}

void GeneratorExpression(Expression * expression, FILE * out) {
	LogDebug("Generating expression..");	
	switch (expression->type) {
		case ADD_EXPRESSION:
			GeneratorExpression(expression->left_expression, out);
			fprintf(out, " + ");
			GeneratorExpression(expression->right_expression, out);
			break;
		case SUB_EXPRESSION:
			GeneratorExpression(expression->left_expression, out);
			fprintf(out, " - ");
			GeneratorExpression(expression->right_expression, out);
			break;
		case MUL_EXPRESSION:
			GeneratorExpression(expression->left_expression, out);
			fprintf(out, " * ");
			GeneratorExpression(expression->right_expression, out);
			break;
		case DIV_EXPRESSION:
			GeneratorExpression(expression->left_expression, out);
			fprintf(out, " / ");
			GeneratorExpression(expression->right_expression, out);
			break;
		case POW_EXPRESSION:
			fprintf(out, "pow(");
			GeneratorExpression(expression->left_expression, out);
			fprintf(out, ", ");
			GeneratorExpression(expression->right_expression, out);
			fprintf(out, ")");
			break;
		case SQRT_EXPRESSION:
			fprintf(out, "sqrt(");
			GeneratorExpression(expression->left_expression, out);
			fprintf(out, ")");
			break;
		case FACT_EXPRESSION:
			fprintf(out, "factorial(");
			GeneratorFactor(expression->factor_expression, out);
			fprintf(out, ")");
			break;
		case FACTOR_EXPRESSION:
			GeneratorFactor(expression->factor_expression, out);
			break;
		default:
			LogInfo("Expression type not found");
			break;
	}	
}

void GeneratorPrint(Print * print_value, FILE * out) {
	LogDebug("Generating print..");
	fprintf(out, "printf(");
	int TYPE = get_expression_type(print_value->expression);
	switch (TYPE) {
		case STRING_TOKEN_TYPE:
			fprintf(out, "\"%%s\\n\", ");
			break;
		case FLOAT_TOKEN_TYPE:
			fprintf(out, "\"%%f\\n\", ");
			break;
		case INTEGER_TOKEN_TYPE:
			fprintf(out, "\"%%d\\n\", ");
			break;
		default:
			LogError("Not a printable type");
			exit(1);
	}
	GeneratorExpression(print_value->expression, out);
	fprintf(out, ")");
}


void GeneratorForeach(Foreach * foreach, FILE * out) {
	LogDebug("Generating foreach..");
	fprintf(out, "foreach(");
	switch (foreach->type) {
		case LIST_FOREACH:
			GeneratorList(foreach->list_value, out);
			break;
		case VARIABLE_FOREACH:
			fprintf(out, "%s", foreach->variable_name);
			break;
		default:
			LogInfo("Foreach type not found");
			break;
	}
	fprintf(out, ", ");
	GeneratorForeachFunctionArgs(foreach->foreach_function_arg, out);
	fprintf(out, ", %d, %d, %d)", foreach->left_value, foreach->right_value, foreach->size);
}

void GeneratorForeachFunctionArgs(ForeachFunctionArg * foreach_function_arg, FILE * out) {
	LogDebug("Generating foreach args..");
	switch (foreach_function_arg->type) {
		case PRINT_FOREACH:
			fprintf(out, "\"print\"");
			break;
		case SQRT_FOREACH:
			fprintf(out, "\"sqrt\"");
			break;
		case FACT_FOREACH:
			fprintf(out, "\"!\"");
			break;
		case ADD_FOREACH:
			fprintf(out, "\"+\"");
			break;
		case MUL_FOREACH:
			fprintf(out, "\"*\"");
			break;
		default:
			LogInfo("ForeachFunctionArgs type not found");
			break;
	}
}

void GeneratorStatFunction(StatFunction * stat_function, FILE * out) {
	LogDebug("Generating stat function..");
	GeneratorStatFunctionType(stat_function->stat_function_type, out);
	fprintf(out, "(");
	switch (stat_function->type) {
		case LIST_STAT_FUNCTION:
			GeneratorList(stat_function->list_value, out);
			break;
		case VARIABLE_STAT_FUNCTION:
			fprintf(out, "%s", stat_function->variable_name);
			break;
		default:
			LogInfo("StatFunction type not found");
			break;
	}
	fprintf(out, ", %d)", stat_function->size);
}

void GeneratorStatFunctionType(StatFunctionType * stat_function_type, FILE * out) {
	LogDebug("Generating stat function type");
	switch (stat_function_type->type) {
		case MEAN_STAT_TYPE: 
			fprintf(out, "mean");
			break;
		case MODE_STAT_TYPE: 
			fprintf(out, "mode");
			break;
		case VARIANCE_STAT_TYPE: 
			fprintf(out, "variance");
			break;
		case KURTOSIS_STAT_TYPE: 
			fprintf(out, "kurtosis");
			break;
		case Q1_STAT_TYPE: 
			fprintf(out, "q1");
			break;
		case Q3_STAT_TYPE: 
			fprintf(out, "q3");
			break;
		case MAX_STAT_TYPE: 
			fprintf(out, "max");
			break;
		case MIN_STAT_TYPE: 
			fprintf(out, "min");
			break;
		case SD_STAT_TYPE: 
			fprintf(out, "sd");
			break;
		case SKEWNESS_STAT_TYPE: 
			fprintf(out, "skewness");
			break;
	}
}

void GeneratorList(List * list_value, FILE * out) {
	LogDebug("Generating list..");
	fprintf(out, "{");
	GeneratorListArgs(list_value->list_args, out);
	fprintf(out, "}");
}

void GeneratorListArgs(ListArgs * list_args, FILE * out) {
	switch (list_args->type) {
		case EXPRESSION_LIST_LISTARGS:
			GeneratorExpression(list_args->expression, out);
			fprintf(out, ", ");
			GeneratorListArgs(list_args->list_args, out);
			break;
		case EXPRESSION_LISTARGS:
			GeneratorExpression(list_args->expression, out);
			break;
	}
}

void GeneratorText(Text * text_value, FILE * out) {
	LogDebug("Generating text..");
	fprintf(out, "%s", text_value->text_value);
}