#include "delete_duplicates.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* p = NULL;
    struct ListNode *slow = head;
    struct ListNode *fast = head->next;
    while (fast != NULL) {
        if (fast->val != slow->val) {
            slow = slow->next;
        } else {
            p = slow->next;
            slow->next = fast->next;
        }
        fast = fast->next;
        if (p) {
            free(p);
            p = NULL;
        }
    }

    return head;
}