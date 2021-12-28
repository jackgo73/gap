#include <string>
#include <vector>
#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* p_head = new ListNode(0, head);
        ListNode *p_left = p_head, *p_right = head;
        ListNode *tmp;
        while (n--) {
            p_right = p_right->next;
        }
        while (p_right) {
            p_left = p_left->next;
            p_right = p_right->next;
        }
        tmp = p_left->next;
        p_left->next = p_left->next->next;
        delete tmp;
        ListNode* ans = p_head->next;
        delete p_head;
        return ans;
    }
};
