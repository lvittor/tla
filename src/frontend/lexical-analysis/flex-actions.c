#include "../../backend/support/logger.h"
#include "../../backend/support/shared.h"
#include "flex-actions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Implementación de "flex-rules.h".
 */

TokenID TokenIDPatternAction(const char * lexeme, TokenID token) {
	LogDebug("TokenIDPatternAction: '%s' with %d.\n", lexeme, token);
	yyval.token = token;
	return token;
}

TokenID IntegerPatternAction(const char * lexeme) {
	LogDebug("IntegerPatternAction: '%s'.\n", lexeme);
	yyval.integer = atoi(lexeme);
	return INTEGER;
}

TokenID FloatPatternAction(const char * lexeme) {
	LogDebug("FloatPatternAction: '%s'.\n", lexeme);
	yyval.float = atof(lexeme);
	return FLOAT;
}

TokenID StringPatternAction(const char * lexeme) {
	LogDebug("StringPatternAction: '%s'.\n", lexeme);
	yyval.string = lexeme;
	return STRING;
}

TokenID ListPatternAction(const char * lexeme){
	LogDebug("ListPatternAction: '%s'.\n", lexeme);
	yyval.string = lexeme;
	return LIST;
}

TokenID VariableNamePatternAction(const char * lexeme){
	LogDebug("VariableNamePatternAction: '%s'.\n", lexeme);
	yyval.string = lexeme;
	return VARIABLE_NAME;
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
