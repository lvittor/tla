#include "backend/code-generation/generator.h"
#include "backend/support/logger.h"
#include "backend/support/shared.h"
#include "backend/support/free-tree.h"
#include "frontend/syntactic-analysis/bison-parser.h"
#include "backend/semantic-analysis/symbol-table.h"
#include <stdio.h>
#include <stdlib.h>

//Estado de la aplicación.
CompilerState state;
FILE * out;

// Punto de entrada principal del compilador.
const int main(const int argumentCount, const char ** arguments) {
	// Inicializar estado de la aplicación.
	state.result = 0;
	state.succeed = false;
	state.main = NULL;

	// Mostrar parámetros recibidos por consola.
	for (int i = 0; i < argumentCount; ++i) {
		LogInfo("Argumento %d: '%s'", i, arguments[i]);
	}

	// Compilar el programa de entrada.
	LogInfo("Compilando...\n");
	symbol_table_init();
	const int result = yyparse();
	switch (result) {
		case 0:
			if (state.succeed) {
				LogInfo("La compilacion fue exitosa.");
				out = fopen("program.c", "w+");
				GeneratorMain(state.main, out);
				if (out == NULL)
					perror("Error");
				fclose(out);
			}
			else {
				LogError("Se produjo un error en la aplicacion.");
				symbol_table_free();
				return -1;
			}
			break;
		case 1:
			LogError("Bison finalizo debido a un error de sintaxis.");
			break;
		case 2:
			LogError("Bison finalizo abruptamente debido a que ya no hay memoria disponible.");
			break;
		default:
			LogError("Error desconocido mientras se ejecutaba el analizador Bison (codigo %d).", result);
	}
	symbol_table_free();
	free_main(state.main);
	LogInfo("Fin.");
	return result;
}
