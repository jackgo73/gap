#ifndef P_00142_DETECT_CYCLE
#define P_00142_DETECT_CYCLE


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head);


#endif //P_00142_DETECT_CYCLE
