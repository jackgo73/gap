#ifndef P_00116_CONNECT
#define P_00116_CONNECT


// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node *connect(Node *root) {
        if (root != nullptr) {
            Node *left = root->left;
            Node *right = root->right;
            while (left != nullptr) {
                left->next = right;
                left = left->right;
                right = right->left;
            }
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};

#endif //P_00116_CONNECT
