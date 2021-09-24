#include "gtest/gtest.h"
#include "p_01143_longest_common_subsequence.c"

TEST(LONGEST_COMMON_SUBSEQUENCE, TEST01) {
    char *w1 = strdup("bdcaba");
    char *w2 = strdup("abcbdab");

    EXPECT_EQ (longestCommonSubsequence(w1,w2), 4);
}
