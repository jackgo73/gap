#ifndef P_00105_BUILD_TREE
#define P_00105_BUILD_TREE

#include <vector>
#include <unordered_map>

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
private:
    unordered_map<int, int> index;
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);

    TreeNode *buildTree(vector<int> &preorder, int preLeft, int preRight, int inLeft, int inRight);
};


#endif //P_00105_BUILD_TREE
