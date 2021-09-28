#include "P_00019_RemoveNthFromEnd.h"

// hdr  1  2  3  4  5
// |       |

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    if (head == NULL || n == 0) {
        return head;
    }
    struct ListNode tmpHdr;
    tmpHdr.next = head;
    struct ListNode *p1 = &tmpHdr, *p2 = &tmpHdr;
    while (n--) {
        p2 = p2->next;
        if (p2 == NULL) {
            return head;
        }
    }
    while (p2->next != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }
    p1->next = p1->next->next;
    return tmpHdr.next;
}