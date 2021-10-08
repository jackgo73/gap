#include "P_00876_MiddleNode.h"

struct ListNode *middleNode(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *p_left = head, *p_right = head;

    while (p_right != NULL && p_right->next != NULL) {
        p_left = p_left->next;
        p_right = p_right->next->next;
    }
    return p_left;
}