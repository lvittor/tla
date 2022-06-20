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
	yylval.token = token;
	LogDebug("Asi esta token: %d\n", yylval.token);
	return token;
}

TokenID IntegerPatternAction(const char * lexeme) {
	LogDebug("IntegerPatternAction: '%s'.\n", lexeme);
	yylval.integer = atoi(lexeme);
	LogDebug("Asi esta integer: %d\n", yylval.integer);
	return INTEGER;
}

TokenID FloatPatternAction(const char * lexeme) {
	LogDebug("FloatPatternAction: '%s'.\n", lexeme);
	yylval.decimal = atof(lexeme);
	return FLOAT;
}

TokenID StringPatternAction(const char * lexeme) {
	LogDebug("StringPatternAction: '%s'.\n", lexeme);
	yylval.string = lexeme;
	return STRING;
}

TokenID ListPatternAction(const char * lexeme){
	LogDebug("ListPatternAction: '%s'.\n", lexeme);
	yylval.string = lexeme;
	return LIST;
}

TokenID VariableNamePatternAction(const char * lexeme){
	LogDebug("VariableNamePatternAction: '%s'.\n", lexeme);
	yylval.string = lexeme;
	LogDebug("Asi queda string: %s\n", yylval.string);
	return VARIABLE_NAME;
}

void IgnoredPatternAction(const char * lexeme) {
	// LogDebug("IgnoredPatternAction:");
}

TokenID EndLinePatternAction(const char * lexeme){
	LogDebug("EndLinePatternAction: '%s'.", lexeme);
	return EOL;
}

TokenID UnknownPatternAction(const char * lexeme) {
	LogDebug("UnknownPatternAction: '%s'.", lexeme);
	return YYUNDEF;
}

TokenID MainPatternAction(const char * lexeme) {
	LogDebug("MainPatternAction: '%s'", lexeme);
	return MAIN;
}

TokenID SemiColonPatternAction(const char * lexeme) {
	LogDebug("SemiColonPatternAction: '%s'", lexeme);
	return SEMICOLON;
}