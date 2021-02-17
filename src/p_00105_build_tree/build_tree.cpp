
#include "build_tree.h"

TreeNode *Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    int preLen = preorder.size();
    int inLen = inorder.size();
    if (preLen != inLen) {
        throw std::runtime_error("Incorrect input data");
    }
    for (int i = 0; i < inLen; ++i) {
        index[inorder[i]] = i;
    }
    return buildTree(preorder, 0, preLen - 1, 0, inLen - 1);
}

TreeNode *
Solution::buildTree(vector<int> &preorder, int preLeft, int preRight, int inLeft, int inRight) {
    if (preLeft > preRight || inLeft > inRight) {
        return nullptr;
    }
    // 前序遍历中的第一个节点就是根节点
    int preRootIdx = preLeft;
    // 在中序遍历中定位根节点
    int inRootIdx = index[preorder[preRootIdx]];

    // 创建根结点
    TreeNode *root = new TreeNode(preorder[preRootIdx]);
    // 左子树节点数目
    int sizeLeftSubtree = inRootIdx - inLeft;

    // 递归地构造左子树，并连接到根节点
    // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
    root->left = buildTree(preorder, preLeft + 1, preLeft + sizeLeftSubtree, inLeft, inRootIdx - 1);
    // 递归地构造右子树，并连接到根节点
    // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
    root->right = buildTree(preorder, preLeft + sizeLeftSubtree + 1, preRight, inRootIdx + 1, inRight);
    return root;
}

