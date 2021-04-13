#include "sorted_list_to_bst.h"

#include "stdlib.h"

struct ListNode {
    int val;
    struct ListNode *next;
};


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *build(struct ListNode* start, struct ListNode* end) {
    if (start == end) {
        return NULL;
    }
    struct ListNode* fast = start;
    struct ListNode* slow = start;
    while (fast != end && fast->next != end) {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = slow->val;
    root->left = root->right = NULL;

    root->left = build(start, slow);
    root->right = build(slow->next, end);
    return root;
}


struct TreeNode *sortedListToBST(struct ListNode *head) {
    return build(head, NULL);
}