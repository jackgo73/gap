#include "gtest/gtest.h"
#include "p_00055_can_jump.c"

TEST(CAN_JUMP, TEST01) {
    int nums[5] = {3, 2, 1, 0, 4};
    EXPECT_EQ (canJump(nums, 5), false);
}

TEST(CAN_JUMP, TEST02) {
    int nums[3] = {2, 0, 0};
    EXPECT_EQ (canJump(nums, 3), true);
}
