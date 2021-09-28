#include "gtest/gtest.h"
#include "P_00019_RemoveNthFromEnd.h"

TEST(P_00019_RemoveNthFromEnd, TEST01) {
    int arr[] = {1, 2, 3, 4, 5};
    ListNode *l = makeListNode1(arr, 5);
    ListNode *r = removeNthFromEnd(l, 2);

    EXPECT_EQ (r->val, 1);
    EXPECT_EQ (r->next->val, 2);
    EXPECT_EQ (r->next->next->val, 3);
    EXPECT_EQ (r->next->next->next->val, 5);
}

TEST(P_00019_RemoveNthFromEnd, TEST02) {
    int arr[] = {1, 2};
    ListNode *l = makeListNode1(arr, 2);
    ListNode *r = removeNthFromEnd(l, 2);

    EXPECT_EQ (r->val, 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
