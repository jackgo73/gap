#include "gtest/gtest.h"
#include "p_00005_longest_palindrome.c"

TEST(LONGEST_PALINDROME, TEST01) {
    EXPECT_STREQ (longestPalindrome(strdup("abcdcd")), strdup("cdc"));
}

TEST(LONGEST_PALINDROME, TEST02) {
    EXPECT_STREQ (longestPalindrome(strdup("ab54c4534d4cd")), strdup("54c45"));
}
