#include "gtest/gtest.h"
#include "p_00326_is_power_of_three.c"

TEST(IS_POWER_OF_THREE, TEST01) {
	EXPECT_EQ (isPowerOfThree(1162261467), true);
}
