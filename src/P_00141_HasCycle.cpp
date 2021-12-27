#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ListNode(vector<int> *array) {
        ListNode head(array->at(0)), *tail = &head;
        for (int i = 1; i < array->size(); i++) {
            tail->next = new ListNode(array->at(i));
            tail = tail->next;
        }
        next = head.next;
        val = array->at(0);
    }
};

class Solution {

public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        while (head != nullptr) {
            if (seen.count(head)) {
                return true;
            }
            seen.insert(head);
            head = head->next;
        }
        return false;
    }
};
