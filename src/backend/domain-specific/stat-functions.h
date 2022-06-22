#ifndef __STAT_FUNCTIONS_HEADER__
#define __STAT_FUNCTIONS_HEADER__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void sort(double * arr, int size);
double max(double * list, int size);
double min(double * list, int size);
double mean(double * list, int size);
double mode(double * list, int size);
double perc_n(double * list, int size, int n);
double q1(double * list, int size);
double q3(double * list, int size);
double variance(double * list, int size);
double sd(double * list, int size);
double skewness(double * list, int size);
double kurtosis(double * list, int size);
int factorial(int input);
int combination(int n, int r);
double binomial(int n, double p, int x);
double poisson(int lambda, int x);
double normal(double mu, double sigma, double x);
int foreach(double * list, char * token, int low, int high, int size);

#endif