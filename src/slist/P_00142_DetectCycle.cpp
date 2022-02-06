#include "P_00142_DetectCycle.h"

#define N 500000

typedef struct htab {
    struct htab *next;
    struct ListNode *val;
} HTAB;


struct ListNode *detectCycle(struct ListNode *head) {
    HTAB *h[N] = {NULL};
    while (head) {
        if (h[abs(head->val)] == NULL) {
            HTAB *k = (HTAB *) malloc(sizeof(HTAB));
            k->val = NULL;
            k->next = NULL;
            h[abs(head->val)] = k;
        }

        HTAB *j = h[abs(head->val)];
        HTAB *pre;
        while (j) {
            if (j->val == head) {
                return head;
            }
            pre = j;
            j = j->next;
        }

        HTAB *p = (HTAB *) malloc(sizeof(HTAB));
        p->val = head;
        p->next = NULL;
        pre->next = p;

        head = head->next;

    }
    return NULL;
}