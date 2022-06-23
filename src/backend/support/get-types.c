#include "get-types.h"

int get_expression_type(Expression * expression) {
	switch (expression->type) {
		case ADD_EXPRESSION:
		case SUB_EXPRESSION:
		case MUL_EXPRESSION:
		case DIV_EXPRESSION:
		case POW_EXPRESSION:
			if (get_expression_type(expression->right_expression) == FLOAT_TOKEN_TYPE || get_expression_type(expression->right_expression) == FLOAT_TOKEN_TYPE)
				return FLOAT_TOKEN_TYPE;
			else 
				return INTEGER_TOKEN_TYPE;
		case SQRT_EXPRESSION:
			return FLOAT_TOKEN_TYPE;
		case FACT_EXPRESSION:
			return INTEGER_TOKEN_TYPE;
		case FACTOR_EXPRESSION:
			return get_factor_type(expression->factor_expression);
	}
}

int get_factor_type(Factor * factor) {
	switch (factor->type) {
		case EXPRESSION_FACTOR:
			return get_expression_type(factor->expression);
		case VALUE_FACTOR:
			return get_value_type(factor->value);
	}
}

int get_value_type(Value * value) {
	switch (value->type) {
		case NUMERIC_VALUE:
			return get_numeric_type(value->numeric_value);
		case TEXT_VALUE:
			return STRING_TOKEN_TYPE;
		case LIST_VALUE:
			return LIST_TOKEN_TYPE;
		case VARIABLE_VALUE:
			Var * var = symbol_table_get(value->variable_name);
			if (var == NULL)
				return -1;
			return var->token_type->type;
		default:
			return -1;
	}
}

int get_numeric_type(Numeric * numeric) {
	switch (numeric->type) {
		case INTEGER_NUMERIC:
			return INTEGER_TOKEN_TYPE;
		case FLOAT_NUMERIC:
		case STAT_NUMERIC:
			return FLOAT_TOKEN_TYPE;
		default:
			return -1;
	}
}