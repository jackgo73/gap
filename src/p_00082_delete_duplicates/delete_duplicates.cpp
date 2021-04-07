#include "delete_duplicates.h"


struct ListNode *deleteDuplicates(struct ListNode *head) {
    struct ListNode dummy = {0, head};
    struct ListNode *slow = &dummy; /* pre指向要删除节点的前驱节点 */
    struct ListNode *fast = NULL;   /* cur指向需要删除的节点       */
    struct ListNode *p = NULL;      /* p指向删除节点的下一个节点   */

    /* 遍历链表 */
    while (slow->next != NULL) {
        fast = slow->next;
        p = fast->next;
        while (p != NULL && p->val == fast->val) { /* 找重复元素 */
            p = p->next;
        }
        if (fast->next != p) { /* 存在重复元素, 需要进行删除 */
            slow->next = p;
        } else {              /* 不存在重复元素, pre继续处理后一个节点 */
            slow = slow->next;
        }
    }
    return dummy.next;
}
