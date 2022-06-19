#ifndef BISON_ACTIONS_HEADER
#define BISON_ACTIONS_HEADER

#include "../../backend/support/shared.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GenericLogger(const char * string);

Program * programGrammarAction(Instructions * instructions);


#endif
