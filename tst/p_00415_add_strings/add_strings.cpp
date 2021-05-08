#include "gtest/gtest.h"
#include "utils.h"
#include "p_00415_add_strings/add_strings.h"

TEST(p_00415_add_strings, basetest1) {
    char *s1 = "123";
    char *s2 = "457";
    char *re = "580";
    char *s3 = addStrings(s1, s2);
    EXPECT_STRCASEEQ(re, s3);
}
