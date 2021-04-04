#include "gtest/gtest.h"
#include "p_00019_remove_nth_from_end/remove_nth_from_end.h"

TEST(p_00019_remove_nth_from_end, basetest1) {
    Solution *s = new Solution();
    ListNode *input = new ListNode(1, new ListNode{2, new ListNode{3, new ListNode{4, new ListNode{5, NULL}}}});
    ListNode *expect = new ListNode(1, new ListNode{2, new ListNode{3, new ListNode{5, NULL}}});
    ListNode *result = s->removeNthFromEnd(input, 2);

    while (result != NULL && expect != NULL) {
        EXPECT_EQ(result->val, expect->val);
        result = result->next;
        expect = expect->next;
    }
}
