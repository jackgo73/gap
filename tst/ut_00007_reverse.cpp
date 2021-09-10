#include "gtest/gtest.h"
#include "p_00007_reverse.c"

TEST(REVERSE, TEST01) {
	EXPECT_EQ (reverse(12345), 54321);
	EXPECT_EQ (reverse(-12345), -54321);
	EXPECT_EQ (reverse(1), 1);
	EXPECT_EQ (reverse(0), 0);
}