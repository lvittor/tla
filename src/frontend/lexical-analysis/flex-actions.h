#ifndef FLEX_ACTIONS_HEADER
#define FLEX_ACTIONS_HEADER

#include "../../backend/support/shared.h"

/**
 * Se definen los diferentes IDs de cada token disponible para el scanner Flex.
 */
typedef enum TokenID {

	// Por defecto, el valor "0" hace fallar el analizador sintáctico.
	UNKNOWN = 0,

	// Código de error de Bison, que permite abortar el escaneo de lexemas cuando
	// se presente un patrón desconocido. El número "257" coincide con el valor
	// que Bison le otorga por defecto, pero además permite que el resto de
	// tokens continúen desde el valor "258" lo que permite proteger los IDs
	// internos que Bison reserva para crear "tokens literales":
	YYUNDEF = 257,

	// Operadores aritméticos.
	ADD,
	SUB,
	MUL,
	DIV,
	FACT,
	POW, 
	SQRT, 

	// Paréntesis.
	OPEN_PARENTHESIS,
	CLOSE_PARENTHESIS,

	OPEN_BRACE, 
	CLOSE_BRACE,

	ASSIGN,

	EQ,
	NE,
	LE,
	GE,
	LT,
	GT,

	SUM_WITH,

	IF, 
	ELSE,

	FOREACH,

	COMMA, 

	INTEGER_TYPE, 
	FLOAT_TYPE,
	STRING_TYPE,
	LIST_TYPE,

	BINOMIAL_DIST_TYPE,
	NORMAL_DIST_TYPE,
	POISSON_DIST_TYPE,

	PRINT,
	INPUT,

	MEAN,
	MODE,
	VARIANCE,
	KURTOSIS,
	Q1,
	Q3,
	MAX,
	MIN,
	SD,
	SKEWNESS, 

	// Tipos de dato.
	INTEGER, 
	FLOAT,
	STRING,
	LIST,

	VARIABLE_NAME,

	EOL,
	EOFF,

} TokenID;

/**
 * Se definen las acciones a ejecutar sobre cada patrón hallado mediante el
 * analizador léxico Flex. Este analizador solo puede identificar
 * construcciones regulares, ya que utiliza un autómata finito determinístico
 * (a.k.a. DFA), como mecanismo de escaneo y reconocimiento.
 */

TokenID OpenBracePatternAction(const char * lexeme);

TokenID CloseBracePatternAction(const char * lexeme);

TokenID IntegerPatternAction(const char * lexeme);

TokenID FloatPatternAction(const char * lexeme);

TokenID StringPatternAction(const char * lexeme);

TokenID VariableNamePatternAction(const char * lexeme);

TokenID ListPatternAction(const char * lexeme);

TokenID AssignPatternAction(const char * lexeme);

TokenID SumWithPatternAction(const char * lexeme);

TokenID IfPatternAction(const char * lexeme);

TokenID ElsePatternAction(const char * lexeme);

TokenID ForeachPatternAction(const char * lexeme);

TokenID CommaPatternAction(const char * lexeme);

TokenID IntegerTypePatternAction(const char * lexeme);

TokenID FloatTypePatternAction(const char * lexeme);

TokenID StringTypePatternAction(const char * lexeme);

TokenID ListTypePatternAction(const char * lexeme);

TokenID BinomialTypePatternAction(const char * lexeme);

TokenID NormalTypePatternAction(const char * lexeme);

TokenID PoissonTypePatternAction(const char * lexeme);

TokenID PrintPatternAction(const char * lexeme);

TokenID InputPatternAction(const char * lexeme);

void IgnoredPatternAction(const char * lexeme);

TokenID EndLinePatternAction(const char * lexeme);

TokenID UnknownPatternAction(const char * lexeme);

#endif
