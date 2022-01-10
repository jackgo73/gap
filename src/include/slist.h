
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

struct ListNode **makeListNode2(const int arr[][], int row, int col) {

}


#endif //GAP_SLIST_H
