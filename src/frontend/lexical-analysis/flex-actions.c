#include "../../backend/support/logger.h"
#include "flex-actions.h"
#include <stdlib.h>

/**
 * Implementación de "flex-rules.h".
 */

TokenID IntegerPatternAction(const char * lexeme) {
	LogDebug("IntegerPatternAction: '%s'.", lexeme);
	yylval = atoi(lexeme);
	return INTEGER;
}

TokenID FloatPatternAction(const char * lexeme){
	LogDebug("FloatPatternAction: '%s'.", lexeme);
	// yylval = atof(lexeme);
	return FLOAT;
}

TokenID VariableNamePatternAction(const char * lexeme){
	LogDebug("VariableNamePatternAction: '%s'.", lexeme);
	return VARIABLE_NAME;
}

TokenID ListPatternAction(const char * lexeme){
	LogDebug("ListPatternAction: '%s'.", lexeme);
	return LIST;
}

void IgnoredPatternAction(const char * lexeme) {
	LogDebug("IgnoredPatternAction: '%s'.", lexeme);
}

TokenID UnknownPatternAction(const char * lexeme) {
	LogDebug("UnknownPatternAction: '%s'.", lexeme);
	return YYUNDEF;
}
