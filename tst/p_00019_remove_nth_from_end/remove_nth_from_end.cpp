#include "gtest/gtest.h"
#include "utils.h"
#include "p_00019_remove_nth_from_end/remove_nth_from_end.h"

TEST(p_00019_remove_nth_from_end, basetest1) {
    int a1[] = {1,2,3,4,5};
    int a2[] = {1,2,3,5};
    struct ListNode *l1 = arrayToList(a1, 5);
    struct ListNode *l2 = arrayToList(a2, 4);
    struct ListNode *res = removeNthFromEnd(l1, 2);

    EXPECT_EQ (res->val, l2->val);
    EXPECT_EQ (res->next->val, l2->next->val);
    EXPECT_EQ (res->next->next->val, l2->next->next->val);
    EXPECT_EQ (res->next->next->next->val, l2->next->next->next->val);
}
