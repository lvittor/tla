#include "../../backend/support/logger.h"
#include "flex-actions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Implementación de "flex-rules.h".
 */

TokenID IntegerPatternAction(const char * lexeme) {
	LogDebug("IntegerPatternAction: '%s'.", lexeme);
	yylval = atoi(lexeme);
	return INTEGER;
}

TokenID StringPatternAction(const char * lexeme){
	LogDebug("StringPatternAction: '%s'.", lexeme);
	return STRING;
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

TokenID AssignPatternAction(const char * lexeme){
	LogDebug("AssignPatternAction: '%s'.", lexeme);
	return ASSIGN;
}

TokenID IntegerTypePatternAction(const char * lexeme){
	LogDebug("IntegerTypePatternAction: '%s'.", lexeme);
	return INTEGER_TYPE;
}

TokenID FloatTypePatternAction(const char * lexeme){
	LogDebug("FloatTypePatternAction: '%s'.", lexeme);
	return FLOAT_TYPE;
}

TokenID StringTypePatternAction(const char * lexeme){
	LogDebug("StringTypePatternAction: '%s'.", lexeme);
	return STRING_TYPE;
}

TokenID ListTypePatternAction(const char * lexeme){
	LogDebug("ListTypePatternAction: '%s'.", lexeme);
	return LIST_TYPE;
}

TokenID ListPatternAction(const char * lexeme){
	LogDebug("ListPatternAction: '%s'.", lexeme);
	return LIST;
}

void IgnoredPatternAction(const char * lexeme) {
	LogDebug("IgnoredPatternAction: '%s'.", lexeme);
}

TokenID EndLinePatternAction(const char * lexeme){
	LogDebug("EndLinePatternAction: '%s'.", lexeme);
	return EOL;
}


TokenID UnknownPatternAction(const char * lexeme) {
	LogDebug("UnknownPatternAction: '%s'.", lexeme);
	return YYUNDEF;
}
