#include "gtest/gtest.h"
#include "p_00046_permute/permute.h"

TEST(p_00046_permute, basetest1) {
    vector<int> intput = {1, 2, 3};
    vector<vector<int>> output = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    auto *s = new Solution();
    EXPECT_EQ (s->permute(intput), output);
}
