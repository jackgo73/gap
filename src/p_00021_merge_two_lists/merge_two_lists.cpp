#include "merge_two_lists.h"

//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4]

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    if (!l1 && !l2) {
        return NULL;
    }
    struct ListNode *p1 = l1, *p2 = l2;
    struct ListNode *d = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *p = d;
    while (p1 || p2) {
        if (p1 && p2) {
            if (p1->val > p2->val) {
                p->next = p2;
                p2 = p2->next;
            } else {
                p->next = p1;
                p1 = p1->next;
            }
        } else if (p1) {
            p->next = p1;
            p1 = p1->next;
        } else if (p2) {
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }
    return d->next;
}