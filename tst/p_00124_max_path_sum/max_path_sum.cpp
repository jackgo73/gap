#include "gtest/gtest.h"
#include "p_00124_max_path_sum/max_path_sum.h"

TEST(p_00124_max_path_sum, basetest1) {
    auto *root = new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    auto *s = new Solution();
    EXPECT_EQ (s->maxPathSum(root), 42);
}
