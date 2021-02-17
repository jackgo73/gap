#ifndef P_00124_MAX_PATH_SUM
#define P_00124_MAX_PATH_SUM


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
    int maxPathSum(TreeNode *root);

    int maxSubPathSum(TreeNode *root, int &max_with_root);
};


#endif //P_00124_MAX_PATH_SUM
