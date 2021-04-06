#include "gtest/gtest.h"
#include "p_00080_remove_duplicates/remove_duplicates.h"

TEST(p_00080_remove_duplicates, basetest1) {
    int input[] = {1, 1, 1, 2, 2, 3};
    removeDuplicates(input, 5);
    EXPECT_EQ (input[2], 2);
    EXPECT_EQ (input[3], 2);
}
