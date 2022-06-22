#include <stdio.h>
#include <stdlib.h>
#include "../src/backend/domain-specific/input-reader.h"
#include "../src/backend/domain-specific/stat-functions.h"

int main() {
	int entry1 = input_int();
	if (entry1 > 0) {
		printf("%s\n", "El factorial de ");
		printf("%d\n", entry1);
		printf("%s\n", "es ");
		printf("%d\n", factorial(entry1));
	} else {
		printf("%s\n", "Se ingreso algo que no es un numero!");
	}
	double entry2 = input_float();
	if (entry2 > 0) {
		printf("%s\n", "Entrada anterior multiplicada a la nueva ");
		printf("%f\n", entry1 * entry2);
	} else {
		printf("%s\n", "Se ingreso algo que no es un numero!");
	}
	char * entry3 = input_string();
	printf("%s\n", entry3);
	return 0;
}