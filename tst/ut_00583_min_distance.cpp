#include "gtest/gtest.h"
#include "p_00583_min_distance.c"

TEST(MIN_DISTANCE, TEST01) {
    char *w1 = strdup("sea");
    char *w2 = strdup("eat");
    EXPECT_EQ (minDistance(w1, w2), 2);
}
