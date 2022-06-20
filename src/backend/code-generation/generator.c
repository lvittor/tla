#include "../support/logger.h"
#include "generator.h"

/**
 * Implementación de "generator.h".
 */

// LogDebug("Generating...");

void GeneratorMain(Main * main, FILE * out) {
	LogDebug("Generating main..");
	fprintf(out, "#include <stdio.h>\n");
	fprintf(out, "#include <stdlib.h>\n\n");
	fprintf(out, "int main() {\n");
	fprintf(out, "\t");
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
		case ONE_INSTRUCTIONS;
			GeneratorInstruction(instructions->instruction, out);
			break;
		default:
			LogInfo("Instructions type not found");
			break;
	}
}

void GeneratorInstruction(Instruction * instruction, FILE * out) {
	LogDebug("Generating instruction..");
	switch (instruction->type) {
		case STATEMENT_INSTRUCTION:
			GeneratorStatement(instruction->statement_instruction, out);
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
	fprintf(out, "\t");
	GeneratorBlock(if_instruction->block, out);
	GeneratorEndIf(if_instruction->end_if, out);
}

void GeneratorCondition(Condition * condition) {
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
	switch (end_if->type) {
		case CLOSE_NORMAL:
			fprintf("}\n");
			break;
		case CLOSE_BLOCK:
			fprintf("} else {\n\t");
			GeneratorBlock(end_if->block, out);
			break;
		default:
			LogInfo("EndIf type not found");
	}
}

void GeneratorCompareOpt(CompareOpt * compare_opt, FILE * out) {
	switch (compare_opt->type) {
		case EQ_COMPARE:
			fprintf(out, "==");
			break;
		case NE_COMPARE:
			fprintf(out, "!=");
			break;
		case LE_COMPARE:
			fprintf(out, "<=");
			break;
		case GE_COMPARE:
			fprintf(out, ">=");
			break;
		case LT_COMPARE:
			fprintf(out, "<");
			break;
		case GT_COMPARE:
			fprintf(out, ">");
			break;
	}
}

void GeneratorFactor(Factor * factor, FILE * out) {
	switch (factor->type) {
		case EXPRESSION_FACTOR:
			fprintf(out, "(");
			GeneratorExpression(factor->expression, out);
			fprintf(out, ")");
			break;
		case VALUE_FACTOR:
			GeneratorValue(factor->value, out);
			break;
	}
}

void GeneratorValue(Value * value, FILE * out) {
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
			GeneratorVariable(value->variable_name, out);
			break;
	}
}

void GeneratorNumeric(Numeric * numeric, FILE * out) {
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
	}
}

void GeneratorDeclare(Declare * declare, FILE * out) {
	switch (declare->type) {
		case EXPRESSION_DECLARE:
			GeneratorType(declare->type_token, out);
			fprintf(out, "%s = ", declare->variable_name);
			GeneratorExpression(declare->expression, out);
			break;
		case DIST_DECLARE:
			GeneratorDistDeclare(declare->dist_declare, out);
			break;
		case INPUT_DECLARE:
			GeneratorType(declare->type_token, out);
			fprintf(out, "%s = input()", declare->variable_name);
			break;
	}
}

void GeneratorType(Token * type_token, FILE * out) {
	switch (type_token->type) {
		case INTEGER_TOKEN_TYPE:
			fprintf(out, "integer ");
			break;
		case FLOAT_TOKEN_TYPE:
			fprintf(out, "float ");
			break;
		case STRING_TOKEN_TYPE:
			fprintf(out, "string ");
			break;
		case LIST_TOKEN_TYPE:
			fprintf(out, "list ");
			break;
	}
}

void GeneratorDistDeclare(DistDeclare * dist_declare, FILE * out) {
	GeneratorDistType(dist_declare->dist_type, out);
	fprintf(" %s", dist_declare->variable_name);
}

void GeneratorDistType(DistType * dist_type, FILE * out) {
	switch (dist_type->type) {
		case BINOMIAL_TYPE:
			GeneratorBinomial(dist_type->binomial, out);
			break;
		case NORMAL_TYPE:
			GeneratorNormal(dist_type->normal, out);
			break;
		case POISSON_TYPE:
			GeneratorPoisson(dist_type->normal, out);
			break;
	}
}

void GeneratorBinomial(Binomial * binomial, FILE * out) {
	fprintf(out, "binomial(");
	switch (binomial->type) {
		case: INTEGER_FLOAT_BINOMIAL:
			fprintf(out, "%d, %f", binomial->int_value, binomial->float_value);
			break;
		case: VARIABLE_VARIABLE_BINOMIAL:
			fprintf(out, "%s, %s", binomial->left_variable_name, binomial->right_variable_name);
			break;
	}
	fprintf(out, ")");
}

void GeneratorNormal(Normal * normal, FILE * out) {
	fprintf(out, "normal(");
	switch (normal->type) {
		case FLOAT_FLOAT_NORMAL:
			fprintf(out, "%f, %f", normal->left_float, normal->right_float);
			break;
		case VARIABLE_VARIABLE_NORMAL:
			fprintf(out, "%s, %s", normal->left_variable_name, normal->right_variable_name);
			break;
		case VARIABLE_SUM_VARIABLE_NORMAL:
			fprintf(out, "%s sumwith %s", normal->left_variable_name, normal->right_variable_name);
			break;
	}
	fprintf(out, ")");
}

void GeneratorPoisson(Poisson * poisson, FILE * out) {
	fprintf(out, "possion(");
	switch (poisson->type) {
		case INTEGER_POISSON:
			fprintf(out, "%d", poisson->int_value);
			break;
		case VARIABLE_POISSON:
			fprintf(out, "%s", possion->variable_name);
			break;
	}
	fprintf(out, ")");
}