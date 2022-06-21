#ifndef __STAT_FUNCTIONS_HEADER__
#define __STAT_FUNCTIONS_HEADER__

#include <math.h>

void sort(double * arr, int size);
double mean(double * list, int size);
double mode(double * list, int size);
double perc_n(double * list, int size, int n);
double median(double * list, int size);
double qtr1(double * list, int size);
double qtr3(double * list, int size);
double variance(double * list, int size);
double stdev(double * list, int size);
double skewness(double * list, int size);
double kurtosis(double * list, int size);
int factorial(int input);

#endif