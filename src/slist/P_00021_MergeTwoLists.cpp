#include "P_00021_MergeTwoLists.h"

#define MAX_ELEMS 100

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {

    struct ListNode hdr, *p = &hdr;
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            p->next = list1;
            list1 = list1->next;
        } else {
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }
    if (list1) {
        p->next = list1;
    } else if (list2) {
        p->next = list2;
    } else {
        p->next = NULL;
    }
    return hdr.next;
}