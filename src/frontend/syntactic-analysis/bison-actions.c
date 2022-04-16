#include "../../backend/domain-specific/calculator.h"
#include "../../backend/support/logger.h"
#include "bison-actions.h"
#include <stdio.h>
#include <string.h>

/**
 * Implementación de "bison-grammar.h".
 */

void yyerror(const char * string) {
	LogError("Mensaje: '%s' debido a '%s' (linea %d).", string, yytext, yylineno);
	LogError("En ASCII es:");
	LogErrorRaw("\t");
	const int length = strlen(yytext);
	for (int i = 0; i < length; ++i) {
		LogErrorRaw("[%d]", yytext[i]);
	}
	LogErrorRaw("\n\n");
}

int ProgramGrammarAction(const int value) {
	LogDebug("ProgramGrammarAction(%d)", value);
	state.succeed = true;
	state.result = value;
	return value;
}

int AdditionExpressionGrammarAction(const int leftValue, const int rightValue) {
	LogDebug("AdditionExpressionGrammarAction(%d, %d)", leftValue, rightValue);
	return Add(leftValue, rightValue);
}

int SubtractionExpressionGrammarAction(const int leftValue, const int rightValue) {
	LogDebug("SubtractionExpressionGrammarAction(%d, %d)", leftValue, rightValue);
	return Subtract(leftValue, rightValue);
}

int MultiplicationExpressionGrammarAction(const int leftValue, const int rightValue) {
	LogDebug("MultiplicationExpressionGrammarAction(%d, %d)", leftValue, rightValue);
	return Multiply(leftValue, rightValue);
}

int DivisionExpressionGrammarAction(const int leftValue, const int rightValue) {
	LogDebug("DivisionExpressionGrammarAction(%d, %d)", leftValue, rightValue);
	return Divide(leftValue, rightValue);
}

int FactorExpressionGrammarAction(const int value) {
	LogDebug("FactorExpressionGrammarAction(%d)", value);
	return value;
}

// ---------------------------------- zeke --------------------------------

size_t FactorialExpressionGrammarAction(const size_t value) {
	LogDebug("FactorialExpressionGrammarAction(%d)", value);
	return value;
}

int ComparisonGrammarAction(const int value){
	LogDebug("ComparisonGrammarAction(%d)", value);
	return value;
}

int EqualComparisonGrammarAction(const int leftValue, const int rightValue){
	LogDebug("EqualComparisonGrammarAction(%d, %d)", leftValue, rightValue);
	return 1;
}

int NotEqualComparisonGrammarAction(const int leftValue, const int rightValue){
	LogDebug("NotEqualComparisonGrammarAction(%d, %d)", leftValue, rightValue);
	return 1;
}

int LowerOrEqualComparisonGrammarAction(const int leftValue, const int rightValue){
	LogDebug("LowerOrEqualComparisonGrammarAction(%d, %d)", leftValue, rightValue);
	return 1;
}

int GreaterOrEqualComparisonGrammarAction(const int leftValue, const int rightValue){
	LogDebug("GreaterOrEqualComparisonGrammarAction(%d, %d)", leftValue, rightValue);
	return 1;
}

int LowerComparisonGrammarAction(const int leftValue, const int rightValue){
	LogDebug("LowerComparisonGrammarAction(%d, %d)", leftValue, rightValue);
	return 1;
}

int GreaterComparisonGrammarAction(const int leftValue, const int rightValue){
	LogDebug("GreaterComparisonGrammarAction(%d, %d)", leftValue, rightValue);
	return 1;
}

// ------------------------------------------------------------------------

int ExpressionFactorGrammarAction(const int value) {
	LogDebug("ExpressionFactorGrammarAction(%d)", value);
	return value;
}

int ConstantFactorGrammarAction(const int value) {
	LogDebug("ConstantFactorGrammarAction(%d)", value);
	return value;
}

int IntegerConstantGrammarAction(const int value) {
	LogDebug("IntegerConstantGrammarAction(%d)", value);
	return value;
}
