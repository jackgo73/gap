#include "gtest/gtest.h"
#include "P_00567_CheckInclusion.h"

TEST(P_00567_CheckInclusion, TEST01) {
    bool res = checkInclusion("ab","eidbaooo");
    EXPECT_EQ (res, true);
}

TEST(P_00567_CheckInclusion, TEST02) {
    bool res = checkInclusion("ab","eidboaoo");
    EXPECT_EQ (res, false);
}

TEST(P_00567_CheckInclusion, TEST03) {
    bool res = checkInclusion("abcdxabcde","abcdeabcdx");
    EXPECT_EQ (res, false);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
