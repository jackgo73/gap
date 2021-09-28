
#ifndef GAP_SLIST_H
#define GAP_SLIST_H

#include <stdlib.h>
#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

#define SizeOfListNode (offsetof(struct ListNode, next) + sizeof(struct ListNode *))


extern struct ListNode *makeListNode1(int const *arr, int cnt);

extern struct ListNode **makeListNode2(int **arr, int row);


#endif //GAP_SLIST_H
