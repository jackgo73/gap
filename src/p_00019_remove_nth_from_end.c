

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode tmpHead = {.val=0, .next=head}, *p = &tmpHead;
    for (; n--; head = head->next);
    for (; head; p = p->next, head = head->next);
    p->next = p->next->next;
    return tmpHead.next;
}