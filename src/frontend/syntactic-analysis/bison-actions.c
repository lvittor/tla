#include "../../backend/domain-specific/calculator.h"
#include "../../backend/support/logger.h"
#include "bison-actions.h"
#include <stdio.h>
#include <string.h>

/**
 * Implementación de "bison-grammar.h".
 */

void yyerror(const char * string) {
	LogError("	Mensaje: '%s' debido a '%s' (linea %d).", string, yytext, yylineno);
	LogError("	En ASCII es:");
	LogErrorRaw("\t");
	const int length = strlen(yytext);
	for (int i = 0; i < length; ++i) {
		LogErrorRaw("[%d]", yytext[i]);
	}
	LogErrorRaw("\n\n");
}

int ProgramGrammarAction(const int value) {
	LogDebug("	ProgramGrammarAction(%d)", value);
	state.succeed = true;
	state.result = value;
	return value;
}

int AdditionExpressionGrammarAction(const int leftValue, const int rightValue) {
	LogDebug("	AdditionExpressionGrammarAction(%d, %d)", leftValue, rightValue);
	return Add(leftValue, rightValue);
}

int SubtractionExpressionGrammarAction(const int leftValue, const int rightValue) {
	LogDebug("	SubtractionExpressionGrammarAction(%d, %d)", leftValue, rightValue);
	return Subtract(leftValue, rightValue);
}

int MultiplicationExpressionGrammarAction(const int leftValue, const int rightValue) {
	LogDebug("	MultiplicationExpressionGrammarAction(%d, %d)", leftValue, rightValue);
	return Multiply(leftValue, rightValue);
}

int DivisionExpressionGrammarAction(const int leftValue, const int rightValue) {
	LogDebug("	DivisionExpressionGrammarAction(%d, %d)", leftValue, rightValue);
	return Divide(leftValue, rightValue);
}

int FactorExpressionGrammarAction(const int value) {
	LogDebug("	FactorExpressionGrammarAction(%d)", value);
	return value;
}

int ExpressionFactorGrammarAction(const int value) {
	LogDebug("	ExpressionFactorGrammarAction(%d)", value);
	return value;
}

int ConstantFactorGrammarAction(const int value) {
	LogDebug("	ConstantFactorGrammarAction(%d)", value);
	return value;
}

int IntegerConstantGrammarAction(const int value) {
	LogDebug("	IntegerConstantGrammarAction(%d)", value);
	return value;
}

int FloatConstantGrammarAction(const float value){
	LogDebug("	FloatConstantGrammarAction(%f)", value);
	return 1;
}

int StringConstantGrammarAction(const int value){
	LogDebug("	StringConstantGrammarAction(%d)", value);
	return 1;
}

int ListConstantGrammarAction(const int list){
	LogDebug("	ListConstantGrammarAction(%d)", list);
	return 1;
}

int DeclareVariableGrammarAction(const int type, const int variableName, const int value){
	LogDebug("	DeclareVariableGrammarAction(%d, %d, %d)", type, variableName, value);
	return 1;
}

int AddVariableReferenceGrammarAction(const int name){
	LogDebug("	AddVariableReferenceGrammarAction(%d)", name);
	return 1;
}