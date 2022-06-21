#include "symbol-table.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

KHASH_MAP_INIT_STR(variables_hash_map, Var *)

static khash_t(variables_hash_map) * variables_map;

static Var * create_var(char * variable_name, Token * token_type);

void symbol_table_init(void) {
    variables_map = kh_init(variables_hash_map);
}

void symbol_table_free(void) {
    Var * var;
    kh_foreach_value(variables_map, var, free(var));
    kh_destroy(variables_hash_map, variables_map);
}

Var * symbol_table_put(char * variable_name, Token * token_type) {
    if (!symbol_table_exists(variable_name)) {
        Var * newVar = create_var(variable_name, token_type);
        int ret;
        khiter_t k = kh_put(variables_hash_map, variables_map, variable_name, &ret);
        if (ret == -1) {
            return NULL;
        }
        kh_val(variables_map, k) = newVar;
        return newVar;
    }
    return NULL;
}

boolean symbol_table_exists(char * variable_name) {
    khiter_t k = kh_get(variables_hash_map, variables_map, variable_name);
    return k != kh_end(variables_map);
}

Var * symbol_table_get(char * variable_name) {
    khiter_t k = kh_get(variables_hash_map, variables_map, variable_name);
    if (k != kh_end(variables_map))
        return kh_val(variables_map, k);
    return NULL;
}

void symbol_table_remove(char * variable_name) {
    khiter_t k = kh_get(variables_hash_map, variables_map, variable_name);
    if (k != kh_end(variables_map))
        kh_del(variables_hash_map, variables_map, k);
}

static Var * create_var(char * variable_name, Token * token_type) {
    Var * newVar = malloc(sizeof(Var));
    newVar->token_type = token_type;
    newVar->variable_name = variable_name;
    newVar->is_dist = false;
    newVar->dist_type = -1;
    return newVar;
}
