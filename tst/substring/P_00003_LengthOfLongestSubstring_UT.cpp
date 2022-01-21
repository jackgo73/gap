#include "gtest/gtest.h"
#include "P_00003_LengthOfLongestSubstring.h"

TEST(P_00003_LengthOfLongestSubstring, TEST01) {
    Solution s;
    EXPECT_EQ (s.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ (s.lengthOfLongestSubstring("bbbbb"), 1);
    EXPECT_EQ (s.lengthOfLongestSubstring("pwwkew"), 3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
