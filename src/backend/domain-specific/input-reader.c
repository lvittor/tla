#include "input-reader.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static char * input_getline(void);

int input_int(void) {
    char * read = input_getline();
    if (read == NULL)
        return -1;
    for (int i = 0; read[i]; i++) {
        if (!isdigit(read[i])) {
            return -1;
        }
    }
    return atoi(read);
}

double input_float(void) {
    char * read = input_getline();
    if (read == NULL)
        return -1;
    char dot = 0;
    for (int i = 0; i < strlen(read); i++) {
        if (!isdigit(read[i])) {
            if (read[i] == '.' && dot == 0) {
                dot = 1;
            } else {
                return -1;
            }
        } 
    }
    return atof(read);
}

char * input_string(void) {
    return input_getline();
}

static char * input_getline(void) {
    char * line = malloc(100), * linep = line;
    size_t lenmax = 100, len = lenmax;
    int c;

    if(line == NULL)
        return NULL;

    for(;;) {
        c = fgetc(stdin);
        if(c == EOF)
            break;
        if(c == '\n')
            break;

        if(--len == 0) {
            len = lenmax;
            char * linen = realloc(linep, lenmax *= 2);

            if(linen == NULL) {
                free(linep);
                return NULL;
            }
            line = linen + (line - linep);
            linep = linen;
        }

        if((*line++ = c) == '\n')
            break;
    }
    *line = '\0';
    return linep;
}