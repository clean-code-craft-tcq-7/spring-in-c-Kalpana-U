#include "stats.h"

#include "gtest/gtest.h"
#include <math.h>

TEST(Statistics, ReportsAverageMinMax) {
    float values[] = {1.5, 8.9, 3.2, 4.5};
    auto computedStats = compute_statistics(values, 4);
    float epsilon = 0.001; // precision margin of error
  //  EXPECT_EQ(computedStats.average, 4.525) why not this
    EXPECT_LT(fabsf(computedStats.average - 4.525), epsilon);
    EXPECT_LT(fabsf(computedStats.max - 8.9), epsilon);
    EXPECT_LT(fabsf(computedStats.min - 1.5), epsilon);
}

TEST(Statistics, AverageNaNForEmpty) {
    float values[] = {};
    auto computedStats = compute_statistics(values, 0);

    EXPECT_TRUE(isnan(computedStats.average));
}

TEST(Statistics, AverageNaNForNumbers) {
    float values[] = {1,1,1,1,1};
    auto computedStats = compute_statistics(values, 5);

    EXPECT_FALSE(isan(computedStats.average));
}

TEST(Statistics, ReportsNegativeValues) {
    float values[] = {1.5, -8.9, 3.2, 4.5};
    auto computedStats = compute_statistics(values, 4);

    EXPECT_EQ(computedStats,-1);
}