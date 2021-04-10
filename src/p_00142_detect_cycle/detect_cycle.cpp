#include "detect_cycle.h"


struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (!fast || !fast->next) {
        return 0;
    }

    slow = head;
    while (slow != fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}