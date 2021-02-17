#include <climits>
#include <algorithm>
#include "max_path_sum.h"

int Solution::maxPathSum(TreeNode *root) {
    if (root == nullptr) return 0;
    int max = INT_MIN;
    maxSubPathSum(root, max);
    return max;
}

int Solution::maxSubPathSum(TreeNode *root, int &max_with_root) {
    if (root == nullptr) return 0;
    // 如果是负数就不要了
    int leftMax = std::max(0, maxSubPathSum(root->left, max_with_root));
    int rightMax = std::max(0, maxSubPathSum(root->right, max_with_root));
    // 带着根结点的三点最优路径
    max_with_root = std::max(max_with_root, root->val + leftMax + rightMax);
    // 带着根结点的两点最优路径，单边最大分支，返回给当前root的父节点计算
    return root->val + std::max(leftMax, rightMax);
}
