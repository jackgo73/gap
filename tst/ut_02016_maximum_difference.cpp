#include "gtest/gtest.h"
#include "p_02016_maximum_difference.c"

TEST(MAXIMUM_DIFFERENCE, TEST01) {
    int nums[] = {7, 1, 5, 4};
    EXPECT_EQ (maximumDifference(nums, 4), 4);
}

TEST(MAXIMUM_DIFFERENCE, TEST02) {
    int nums[] = {9, 4, 3, 2};
    EXPECT_EQ (maximumDifference(nums, 4), -1);
}

TEST(MAXIMUM_DIFFERENCE, TEST03) {
    int nums[] = {1, 5, 2, 10};
    EXPECT_EQ (maximumDifference(nums, 4), 9);
}


