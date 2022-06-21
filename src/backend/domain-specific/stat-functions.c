#include "stat-functions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void sort(double * arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

double mean(double * list, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum += list[i];
    return sum / size;
}

double mode(double * list, int size) {
    sort(list, size);
    double mode = 0;
    int occurrences = 0;
    int last_occurrences = 0;
    for (int i = 0; i < size-1; i++) {
        occurrences += 1;
        if (list[i] != list[i+1]) {
            mode = occurrences > last_occurrences ? list[i] : mode;
            last_occurrences = occurrences;
            occurrences = 0;
        }
    }
    return mode;
}

double perc_n(double * list, int size, int n) {
    sort(list, size);
    int f = (int) floor(size * n / 100.0);
    int c = (int) ceil(size * n / 100.0);
    double v = f == c ? list[f-1] : (list[f-1] + list[c-1]) / 2;
    return v;
}

double median(double * list, int size) {
    return perc_n(list, size, 50);
}

double qtr1(double * list, int size) {
    return perc_n(list, size, 25);
}

double qtr3(double * list, int size) {
    return perc_n(list, size, 75);
}

double variance(double * list, int size) {
    if (size < 2) return 0.0;
    double sum = 0;
    double _mean = mean(list, size);
    for (int i = 0; i < size; i++)
        sum += pow(list[i] - _mean, 2);
    return sum / (size - 1);
}

double stdev(double * list, int size) {
    return sqrt(variance(list, size));
}

double skewness(double * list, int size) {
    if (size < 2) return 0.0;
    double sum = 0;
    double _mean = mean(list, size);
    for (int i = 0; i < size; i++)
        sum += pow(list[i] - _mean, 3);
    return sum / (pow(stdev(list, size), 3) * size);
}

double kurtosis(double * list, int size) {
    if (size < 2) return 0.0;
    double sum = 0;
    double _mean = mean(list, size);
    for (int i = 0; i < size; i++)
        sum += pow(list[i] - _mean, 4);
    return sum / (pow(stdev(list, size), 4) * size);
}

int factorial(int input) {
    if (input < 0)
        return 0;
        
    for (int i = input-1; i >0; i--)
        input*=i;
    
    return input;
}

int combination(int n, int r) {
    if (n<r || n<0 || r<0)
        return -1;
    return factorial(n)/(factorial(n-r)*factorial(r));
}

double binomial(int n, double p, int x) {
    if (n < 0 || p < 0)
        return -1;
    return combination(n, x) * pow(p, x) * pow((1 - p), n - x);
}

double poisson(int lambda, int x) {
    if (lambda < 0 || x < 0) 
        return -1;
    return (pow(M_E, -1 * lambda) * pow(lambda, x)) / factorial(x);
}

double normal(double mu, double sigma, double x) {
    if (sigma < 0)
        return -1;
    return (1/(sigma*(sqrt(2*M_PI))))*(pow(M_E, -1 * ((pow(x - mu, 2))/(2 * pow(sigma, 2)))));
}