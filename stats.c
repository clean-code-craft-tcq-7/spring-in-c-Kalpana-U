#include "stats.h"
#include <stddef.h>
#include <float.h>
#include <math.h>

struct Stats compute_statistics(const float* numbers, int count) {
    struct Stats stats;
    float sum = 0.0f;
    stats.min = FLT_MAX; // most maximum
    stats.max = -FLT_MAX; // most minimum

    for (int i=0; i<count; i++) {
         if (numbers[j] < 0) {
            stats.min = -1;
            stats.max = -1;
            stats.average = -1;
            return stats;
        }

        if (numbers[i] > stats.max) {
            stats.max = numbers[i];
        }
        if (numbers[i] < stats.min) {
            stats.min = numbers[i];
        }
        sum += numbers[i];
        
    }

    stats.average = sum/count;

    if (stats.average == NAN) {
        return stats;
    }

    return stats;
}