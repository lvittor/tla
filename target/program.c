#include <stdio.h>
#include <stdlib.h>
#include "../src/backend/domain-specific/stat-functions.h"

int main() {
	double data[] = {21.300000, 38.400000, 12.700000, 41.600000, 51.800000, 12.500000};
	printf("%s\n", "The max is");
	printf("%f\n", max(data, 6));
	printf("%s\n", "The min is:");
	printf("%f\n", min(data, 6));
	printf("%s\n", "The mean is:");
	printf("%f\n", mean(data, 6));
	printf("%s\n", "The mode is:");
	printf("%f\n", mode(data, 6));
	printf("%s\n", "The q1 is:");
	printf("%f\n", q1(data, 6));
	printf("%s\n", "The q3 is");
	printf("%f\n", q3(data, 6));
	printf("%s\n", "The standard deviation is:");
	printf("%f\n", sd(data, 6));
	printf("%s\n", "The variance is:");
	printf("%f\n", variance(data, 6));
	printf("%s\n", "The kurtosis is:");
	printf("%f\n", kurtosis(data, 6));
	printf("%s\n", "The skewness is:");
	printf("%f\n", skewness(data, 6));
	return 0;
}