
#ifndef GAP_SLIST_H
#define GAP_SLIST_H

#include <stdlib.h>
#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

#define SizeOfListNode (offsetof(struct ListNode, next) + sizeof(struct ListNode *))

struct ListNode *makeListNode1(const int *arr, int cnt) {
    struct ListNode *startPos = (struct ListNode *) malloc(cnt * SizeOfListNode), *p = startPos;
    int i = 0;
    for (; i < cnt - 1; i++) {
        p->val = arr[i];
        p->next = p + SizeOfListNode;
        p = p->next;
    }
    p->val = arr[i];
    p->next = NULL;
    return startPos;
}

struct ListNode **makeListNode2(int **arr, int row) {
    struct ListNode **r = (struct ListNode **) malloc(sizeof(struct ListNode *) * row);
    for (int i = 0; i < row; ++i) {
        int *curRow = arr[i];
        int cntRow = curRow[0];
        r[i] = (struct ListNode *) malloc(SizeOfListNode * cntRow);
        struct ListNode *p = r[i];
        for (int j = 0; j < cntRow - 1; ++j) {
            p->val = curRow[j + 1];
            p->next = p + 1;
            p = p->next;
        }
        p->val = curRow[cntRow];
        p->next = NULL;
    }
    return r;
}


#endif //GAP_SLIST_H
