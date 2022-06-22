#include "stat-functions.h"
#include "z-index-table.h"
#include <math.h>
#include <string.h>

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

double max(double * list, int size) {
    sort(list, size);
    return list[size - 1];
}

double min(double * list, int size) {
    sort(list, size);
    return list[0];
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

double q1(double * list, int size) {
    return perc_n(list, size, 25);
}

double q3(double * list, int size) {
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

double sd(double * list, int size) {
    return sqrt(variance(list, size));
}

double skewness(double * list, int size) {
    if (size < 2) return 0.0;
    double ans = 0;
    double sum = 0;
    double _mean = mean(list, size);
    for (int i = 0; i < size; i++)
        sum += pow(list[i] - _mean, 3);
    ans = sum / size;
    ans = ans / pow(sd(list, size), 3);
    return ans;
}

double kurtosis(double * list, int size) {
    if (size < 2) return 0.0;
    double ans = 0;
    double sum = 0;
    double _mean = mean(list, size);
    for (int i = 0; i < size; i++)
        sum += pow(list[i] - _mean, 4);
    ans = sum / size;
    ans = ans / pow(sd(list, size), 4);
    return ans;
}

int factorial(int input) {
    if (input < 0)
        return 0;
    if (input == 0)
        return 1;
        
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
    return get_normal_probability(mu, sigma, x);    
}

int foreach(double * list, char * token, int low, int high, int size) {
    if (high > size - 1) {
        return -1;
    }
    if (strcmp(token, "print") == 0){
        printf("[");
        for (int i = low; i < high + 1; i++) {
            printf("%f", list[i]);
            if (i != high)
                printf(", ");
        }
        printf("]\n");
    } else if (strcmp(token, "sqrt") == 0) {
        printf("[");
        for (int i = low; i < high + 1; i++) {
            printf("%f", sqrt(list[i]));
            if (i != high)
                printf(", ");
        }
        printf("]\n");
    } else if (strcmp(token, "!") == 0) {
        printf("[");
        for (int i = low; i < high + 1; i++) {
            printf("%d", factorial(roundf(list[i])));
            if (i != high)
                printf(", ");
        }
        printf("]\n");
    } else if (strcmp(token, "+") == 0) {
        double ans = 0;
        for (int i = low; i < high + 1; i++) 
            ans += list[i];
        printf("%f\n", ans);
    } else if (strcmp(token, "*") == 0) {
        double ans = 1;
        for (int i = low; i < high + 1; i++) 
            ans *= list[i];
        printf("%f\n", ans);
    } else {
        return -1;
    }
    return 1;
}