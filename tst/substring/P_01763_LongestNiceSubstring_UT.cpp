#include "gtest/gtest.h"
#include "P_01763_LongestNiceSubstring.h"

TEST(P_01763_LongestNiceSubstring, TEST01) {
    const char *i = "YazaAay";
    const char *e = "aAa";
    char *r = longestNiceSubstring((char *) i);
    EXPECT_STRCASEEQ(r, e);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
