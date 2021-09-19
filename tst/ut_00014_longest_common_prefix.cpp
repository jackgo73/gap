#include "gtest/gtest.h"
#include "p_00014_longest_common_prefix.c"

TEST(LONGEST_COMMON_PREFIX, TEST01) {
    char **input;
    input = (char **) malloc(sizeof(char *) * 3);
    input[0] = strdup("abcdef");
    input[1] = strdup("abzde");
    input[2] = strdup("abdef");
    EXPECT_STRCASEEQ(longestCommonPrefix(input, 3), "ab");
}

TEST(LONGEST_COMMON_PREFIX, TEST02) {
    char **input = NULL;
    EXPECT_STRCASEEQ(longestCommonPrefix(input, 0), "");
}

TEST(LONGEST_COMMON_PREFIX, TEST03) {
    char **input;
    input = (char **) malloc(sizeof(char *) * 2);
    input[0] = strdup("");
    input[1] = strdup("");
    EXPECT_STRCASEEQ(longestCommonPrefix(input, 2), "");
}