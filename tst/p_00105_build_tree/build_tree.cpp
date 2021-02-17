#include "gtest/gtest.h"
#include "p_00105_build_tree/build_tree.h"

TEST(p_00105_build_tree, basetest1) {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    auto *res = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    auto *s = new Solution();
    EXPECT_EQ (s->buildTree(preorder, inorder)->left->val, 9);
    EXPECT_EQ (s->buildTree(preorder, inorder)->val, 3);
    EXPECT_EQ (s->buildTree(preorder, inorder)->right->right->val, 7);
    EXPECT_EQ (s->buildTree(preorder, inorder)->right->left->val, 15);
}

TEST(p_00105_build_tree, basetest2) {
    vector<int> preorder = {1, 2, 3};
    vector<int> inorder = {3, 2, 1};
    auto *res = new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);

    auto *r = Solution().buildTree(preorder, inorder);

    EXPECT_EQ (r->val, 1);
    EXPECT_EQ (r->left->val, 2);
    EXPECT_EQ (r->left->left->val, 3);
}
