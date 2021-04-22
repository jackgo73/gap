
#include "add_two_numbers.h"


struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;

    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *res = dummy;

    int carry = 0;
    while (p1 || p2) {
        int t1 = 0;
        int t2 = 0;
        int sum = 0;
        if (p1) {
            t1 = p1->val;
            p1 = p1->next;
        }
        if (p2) {
            t2 = p2->val;
            p2 = p2->next;
        }
        sum = t1 + t2 + carry;
        carry = sum / 10;
        sum = sum % 10;

        res->next = (struct ListNode *) malloc(sizeof(struct ListNode));
        res->next->val = sum;
        res = res->next;
    }
    if (carry) {
        struct ListNode cur = {.val=1, .next=NULL};
        res->next = &cur;
    }

    return dummy->next;
}