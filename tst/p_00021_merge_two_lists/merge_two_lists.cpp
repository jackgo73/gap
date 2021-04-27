#include "gtest/gtest.h"
#include "utils.h"
#include "p_00021_merge_two_lists/merge_two_lists.h"

TEST(p_00021_merge_two_lists, basetest1) {
    int a1[] = {1, 2, 4};
    int a2[] = {1, 3, 4};
    int a3[] = {1, 1, 2, 3, 4, 4};
    struct ListNode *l1 = arrayToList(a1, 3);
    struct ListNode *l2 = arrayToList(a2, 3);
    struct ListNode *l3 = arrayToList(a3, 6);
    struct ListNode *res = mergeTwoLists(l1, l2);

    EXPECT_EQ (res->val, l3->val);
    EXPECT_EQ (res->next->val, l3->next->val);
    EXPECT_EQ (res->next->next->val, l3->next->next->val);
}
