#include "z-index-table.h"
#include <stdio.h>
#include <math.h>

double get_normal_probability(double mu, double sigma, double x) {
    double seek = (x - mu) / sigma;
    char is_neg = 0;
    if (seek < 0) {
        is_neg = 1;
        seek = fabs(seek);
    }
    seek = roundf(seek * 100) / 100;
    int row = floorf(seek * 10);
    int col = seek * 10 - floorf(seek * 10);
    if (is_neg == 1) {
        if (seek > 3.9)
            return 0;
        return 1 - z_table[row][col];
    }
    if (seek > 3.9)
        return 1;
    else
        return z_table[row][col];
    
}