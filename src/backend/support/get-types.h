#ifndef __GET_TYPES_HEADER__
#define __GET_TYPES_HEADER__

#include "shared.h"
#include "../../frontend/syntactic-analysis/bison-parser.h"
#include "../../backend/semantic-analysis/symbol-table.h"

int get_expression_type(Expression * expression);
int get_factor_type(Factor * factor);
int get_value_type(Value * value);
int get_numeric_type(Numeric * numeric);

#endif