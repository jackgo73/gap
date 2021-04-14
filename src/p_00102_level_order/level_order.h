#ifndef P_00102_LEVEL_ORDER
#define P_00102_LEVEL_ORDER

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

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> levelOrder(TreeNode *root) {
        build(root, 0);
        return res;
    }

    void build(TreeNode *root, int level) {
        if (!root) {
            return;
        }
        if (level >= res.size()) {
            res.emplace_back();
        }
        res[level].push_back(root->val);
        build(root->left, level + 1);
        build(root->right, level + 1);
    }
};


#endif //P_00102_LEVEL_ORDER
