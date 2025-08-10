#include "stats.h"
#include <stddef.h>
#include <float.h>

struct Stats compute_statistics(const float* numbers, int count) {
    struct Stats stats;
    float sum = 0.0f;
    stats.min = FLT_MAX; // most maximum
    stats.max = -FLT_MAX; // most minimum

    for (int i=0; i<count; i++) {
        if (numbers[i] > stats.max) {
            stats.max = numbers[i];
        }
        if (numbers[i] < stats.min) {
            stats.min = numbers[i];
        }
        sum += numbers[i];
        
    }

    stats.average = sum/count;
    return stats;
}