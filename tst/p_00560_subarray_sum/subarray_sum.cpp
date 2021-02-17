#include "gtest/gtest.h"
#include "p_00560_subarray_sum/subarray_sum.h"

TEST(p_00560_subarray_sum, basetest1) {
    vector<int> nums = {1,1,1};
    Solution *s = new Solution();
    EXPECT_EQ (s->subarraySumEasy(nums, 2), 2);
    EXPECT_EQ (s->subarraySum(nums, 2), 2);
}

TEST(p_00560_subarray_sum, basetest2) {
    vector<int> nums = {3,4,7,2,-3,1,4,2};
    Solution *s = new Solution();
    EXPECT_EQ (s->subarraySumEasy(nums, 7), 4);
    EXPECT_EQ (s->subarraySum(nums, 7), 4);
}
