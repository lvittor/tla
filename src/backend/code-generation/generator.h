#ifndef GENERATOR_HEADER
#define GENERATOR_HEADER

#include "../support/shared.h"
#include "../../frontend/syntactic-analysis/bison-parser.h"

void GeneratorMain(Main * main, FILE * out);
void GeneratorProgram(Program * program, FILE * out);

#endif
