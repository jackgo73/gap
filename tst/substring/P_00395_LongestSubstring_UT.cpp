#include "gtest/gtest.h"
#include "P_00395_LongestSubstring.h"

TEST(P_00395_LongestSubstring, TEST01) {
    char *s = "ababbc";
    int k = 2;
    int r = longestSubstring(s, k);
    EXPECT_EQ (r, 5);
}


TEST(P_00395_LongestSubstring, TEST02) {
    char *s = "abcdedghijklmnopqrstuvwxyz";
    int k = 2;
    int r = longestSubstring(s, k);
    EXPECT_EQ (r, 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
