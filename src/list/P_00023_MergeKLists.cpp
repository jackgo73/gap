#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    struct Node {
        int val;
        ListNode *ptr;
        bool operator<(const Node &rhs) const {
            return val > rhs.val;
        }
    };
    priority_queue<Node> queue;
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        for(ListNode *node : lists) {
            if(node) {
                queue.push({node->val, node});
            }
        }
        ListNode head;
        ListNode *tail = &head;
        while (!queue.empty()) {
            Node node = queue.top();
            queue.pop();
            tail->next = node.ptr;
            tail = tail->next;
            if (node.ptr->next) {
                queue.push({node.ptr->next->val, node.ptr->next});
            }
        }
        return head.next;
    }
};


class Solution1 {
public:
    struct Status {
        int val;
        ListNode *ptr;

        bool operator<(const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue<Status> q;

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        for (auto node: lists) {
            if (node) q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top();
            q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};
