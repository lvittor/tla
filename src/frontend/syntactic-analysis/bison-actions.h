#ifndef BISON_ACTIONS_HEADER
#define BISON_ACTIONS_HEADER

#include "../../backend/support/shared.h"

// typedef ast_node *_ast_node;

// struct _integer_node {
//     char * integer;
// };

// struct _float_node {
//     char * ffloat;
// };

// struct _string_node {
//     char * string;
// };

// struct _list_node {
//     char * list;
// };

// struct _variable_node {
//     int declared;   // TODO: Revisar si sirve este parametro
//     int type;       // Tipo de la variable
//     char * name;    // Nombre de la variable
//     ast_node value;
// };

// struct _expression_node {
//     ast_node first;
//     ast_node second;
//     ast_node third;
// };

// struct _ast_node_list {
//     ast_node node;
//     struct _ast_node_list * next;
// };

// typedef struct _ast_node { 
//     enum {
//         // Tipos de datos
//         INTEGER_NODE, 
//         FLOAT_NODE, 
//         STRING_NODE, 
//         LIST_NODE,

//         VARIABLE_NODE, 

//         EXPRESSION_NODE,

//         AST_LIST_NODE,
//     } _node_t;

//     union {
//         struct _integer_node integer_node;
//         struct _float_node float_node;
//         struct _string_node string_node;
//         struct _list_node list_node;

//         struct _variable_node variable_node;
        
//         struct _expression_node expression_node; 
        
//         struct _ast_node_list ast_node_list;
//     };
// } _ast_node;

/**
 * Se definen las acciones a ejecutar sobre cada regla de producción de la
 * gramática. El objetivo de cada acción debe ser el de construir el nodo
 * adecuado que almacene la información requerida en el árbol de sintaxis
 * abstracta (i.e., el AST).
 */

void GenericLogger(const char * string);

// Programa.
int ProgramGrammarAction(const int value);

// Expresión.
int AdditionExpressionGrammarAction(const int leftValue, const int rightValue);
int SubtractionExpressionGrammarAction(const int leftValue, const int rightValue);
int MultiplicationExpressionGrammarAction(const int leftValue, const int rightValue);
int DivisionExpressionGrammarAction(const int leftValue, const int rightValue);
int FactorExpressionGrammarAction(const int value);

size_t FactorialExpressionGrammarAction(const size_t value);

// Factores.
int ExpressionFactorGrammarAction(const int value);
int ConstantFactorGrammarAction(const int value);

// Constantes.
int IntegerConstantGrammarAction(const int value);
int FloatConstantGrammarAction(const float value);
int StringConstantGrammarAction(const int value);
int ListConstantGrammarAction(const int list);

// Variables.
int DeclareVariableGrammarAction(const int type, const int variableName, const int value);

int AddVariableReferenceGrammarAction(const int name);

#endif
