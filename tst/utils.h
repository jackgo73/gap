

#ifndef ROTATE_UTILS_H
#define ROTATE_UTILS_H

#include <stdlib.h>
#include <stdio.h>

#include "common.h"

struct ListNode *arrayToList(int *arr, int n) {
    if (!arr || n < 1) {
        return NULL;
    }
    struct ListNode *head = (struct ListNode *) malloc(n * sizeof(struct ListNode));
    struct ListNode *p = head;

    int i;
    for (i = 0; i < n - 1; i++, p = p->next) {
        p->val = *(arr + i);
        p->next = p + 1;
    }
    p->val = *(arr + i);
    p->next = NULL;

    return head;
}

#endif //ROTATE_UTILS_H
