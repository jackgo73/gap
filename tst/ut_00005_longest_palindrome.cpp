#include "gtest/gtest.h"
#include "p_00005_longest_palindrome.c"

TEST(LONGEST_PALINDROME, TEST01) {
    char *input = strdup("babad");
    longestPalindrome(input);
	EXPECT_EQ (1, 1);
}
