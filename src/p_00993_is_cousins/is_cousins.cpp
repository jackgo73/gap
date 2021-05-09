#include "is_cousins.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct res {
    struct TreeNode *father;
    int depth;
};

struct res getdepth(struct TreeNode *root, int val, int thedepth) {
    struct res result = {root, thedepth + 1};
    if (!root->left && !root->right) {
        result.depth = -1;
        return result;
    }
    if (root->left && root->left->val == val)
        return result;
    if (root->right && root->right->val == val)
        return result;

    struct res res1 = {0, -1}, res2 = {0, -1};
    if (root->left)
        res1 = getdepth(root->left, val, thedepth + 1);
    if (root->right)
        res2 = getdepth(root->right, val, thedepth + 1);
    return res1.depth > 0 ? res1 : res2;

}

bool isCousins(struct TreeNode *root, int x, int y) {
    struct res res1 = getdepth(root, x, 0), res2 = getdepth(root, y, 0);
    if (res1.depth == res2.depth && res1.father != res2.father)
        return true;
    return false;
}
