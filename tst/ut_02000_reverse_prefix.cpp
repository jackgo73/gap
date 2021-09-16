#include "gtest/gtest.h"
#include "p_02000_reverse_prefix.c"

TEST(REVERSE_PREFIX, TEST01) {
    char *word = strdup("abcdefd");
    char ch = 'd';
    EXPECT_STRCASEEQ(reversePrefix(word, ch), "dcbaefd");
}
