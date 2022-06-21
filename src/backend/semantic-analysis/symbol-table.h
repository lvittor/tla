#ifndef __SYMBOL_TABLE_HEADER__
#define __SYMBOL_TABLE_HEADER__

#include "khash.h"
#include "../support/shared.h"

typedef struct Var {
	Token * token_type;
    boolean is_dist;
    DistTypeType dist_type;
	char * variable_name;
} Var;

void symbol_table_init(void);
void symbol_table_free(void);
Var * symbol_table_put(char * variable_name, Token * token_type);
boolean symbol_table_exists(char * variable_name);
Var * symbol_table_get(char * variable_name);
void symbol_table_remove(char * variable_name);

#endif