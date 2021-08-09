#include "gtest/gtest.h"
#include "p_00704_search/search.h"


TEST(p_00704_search, basetest1) {
    vector<int> input = {1,4,5,6,7,11,12,44};
    int i = Solution().search(input, 12);
    EXPECT_EQ (i, 6);
}
