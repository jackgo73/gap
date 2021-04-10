#include "has_cycle.h"

#include "stdio.h"

bool hasCycle(struct ListNode *head) {
    for (struct ListNode *slow = head, *fast = head; fast && fast->next;) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}
