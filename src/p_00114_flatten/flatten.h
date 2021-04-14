#ifndef P_00114_FLATTEN
#define P_00114_FLATTEN

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Solution {
    vector<TreeNode*> tmp;

    void flatten(TreeNode *root) {
        build(root);
        for (int i = 1; i < tmp.size(); i++) {
            TreeNode *prev = tmp[i - 1];
            TreeNode *curr = tmp[i];
            prev->left = nullptr;
            prev->right = curr;
        }

    }

    void build(TreeNode *node) {
        if (node) {
            tmp.push_back(node);
            build(node->left);
            build(node->right);
        }
    }
};


#endif //P_00114_FLATTEN
