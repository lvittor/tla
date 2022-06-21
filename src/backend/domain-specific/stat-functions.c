#include "stat-functions.h"

// MEAN
// MODE
// VARIANCE
// KURTOSIS
// Q1
// Q3
// MAX
// MIN
// SD
// SKEWNES

float mean(float * array, int size) {
    float ans = 0.0;
    for (int i = 0; i < size; i++) {
        ans += array[i];
    }
    return ans / size;
}