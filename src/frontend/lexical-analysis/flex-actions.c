#include "../../backend/support/logger.h"
#include "flex-actions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Implementación de "flex-rules.h".
 */

TokenID OpenBracePatternAction(const char * lexeme){
	//LogDebug("OpenBracePatternAction: '%s'.", lexeme);
	return OPEN_BRACE;
}

TokenID CloseBracePatternAction(const char * lexeme){
	//LogDebug("CloseBracePatternAction: '%s'.", lexeme);
	return CLOSE_BRACE;
}

TokenID IntegerPatternAction(const char * lexeme) {
	//LogDebug("IntegerPatternAction: '%s'.", lexeme);
	yylval = atoi(lexeme);
	return INTEGER;
}

TokenID StringPatternAction(const char * lexeme){
	//LogDebug("StringPatternAction: '%s'.", lexeme);
	return STRING;
}

TokenID FloatPatternAction(const char * lexeme){
	//LogDebug("FloatPatternAction: '%s'.", lexeme);
	// yylval = atof(lexeme);
	return FLOAT;
}

TokenID VariableNamePatternAction(const char * lexeme){
	//LogDebug("VariableNamePatternAction: '%s'.", lexeme);
	return VARIABLE_NAME;
}

TokenID AssignPatternAction(const char * lexeme){
	//LogDebug("AssignPatternAction: '%s'.", lexeme);
	return ASSIGN;
}

TokenID SumWithPatternAction(const char * lexeme){
	//LogDebug("SumWithPatternAction: '%s'.", lexeme);
	return SUM_WITH;
}

TokenID IfPatternAction(const char * lexeme){
	//LogDebug("IfPatternAction: '%s'.", lexeme);
	return IF;
}

TokenID ElsePatternAction(const char * lexeme){
	//LogDebug("ElsePatternAction: '%s'.", lexeme);
	return ELSE;
}

TokenID ForeachPatternAction(const char * lexeme){
	//LogDebug("ForeachPatternAction: '%s'.", lexeme);
	return FOREACH;
}

TokenID CommaPatternAction(const char * lexeme){
	//LogDebug("CommaPatternAction: '%s'.", lexeme);
	return COMMA;
}

TokenID IntegerTypePatternAction(const char * lexeme){
	//LogDebug("IntegerTypePatternAction: '%s'.", lexeme);
	yylval.token = INTEGER_TYPE;
	return INTEGER_TYPE;
}

TokenID FloatTypePatternAction(const char * lexeme){
	//LogDebug("FloatTypePatternAction: '%s'.", lexeme);
	return FLOAT_TYPE;
}

TokenID StringTypePatternAction(const char * lexeme){
	//LogDebug("StringTypePatternAction: '%s'.", lexeme);
	return STRING_TYPE;
}

TokenID ListTypePatternAction(const char * lexeme){
	//LogDebug("ListTypePatternAction: '%s'.", lexeme);
	return LIST_TYPE;
}

TokenID BinomialTypePatternAction(const char * lexeme){
	//LogDebug("BinomialTypePatternAction: '%s'.", lexeme);
	return BINOMIAL_DIST_TYPE; 
}

TokenID NormalTypePatternAction(const char * lexeme){
	//LogDebug("NormalTypePatternAction: '%s'.", lexeme);
	return NORMAL_DIST_TYPE;
}

TokenID PoissonTypePatternAction(const char * lexeme){
	//LogDebug("PoissonTypePatternAction: '%s'.", lexeme);
	return POISSON_DIST_TYPE;
}

TokenID PrintPatternAction(const char * lexeme){
	//LogDebug("PrintPatternAction: '%s'.", lexeme);
	return PRINT;
}

TokenID InputPatternAction(const char * lexeme){
	//LogDebug("InputPatternAction: '%s'.", lexeme);
	return INPUT;
}

TokenID ListPatternAction(const char * lexeme){
	//LogDebug("ListPatternAction: '%s'.", lexeme);
	return LIST;
}

void IgnoredPatternAction(const char * lexeme) {
	//LogDebug("IgnoredPatternAction: '%s'.", lexeme);
}

TokenID EndLinePatternAction(const char * lexeme){
	//LogDebug("EndLinePatternAction: '%s'.", lexeme);
	return EOL;
}


TokenID UnknownPatternAction(const char * lexeme) {
	//LogDebug("UnknownPatternAction: '%s'.", lexeme);
	return YYUNDEF;
}
