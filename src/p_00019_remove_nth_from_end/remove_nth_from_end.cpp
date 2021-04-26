#include "remove_nth_from_end.h"

// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
// 1  2  3  4  5  n = 2
// 1  2  3     5

// 1  n = 1
//

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = 0, dummy->next = head;
    struct ListNode *first = head;
    struct ListNode *second = dummy;
    for (int i = 0; i < n; ++i) {
        first = first->next;
    }
    while (first) {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    struct ListNode *ans = dummy->next;
    free(dummy);
    return ans;
}
