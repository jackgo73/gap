#include "gtest/gtest.h"
#include "P_00021_MergeTwoLists.h"

TEST(P_00876_MiddleNode, TEST01) {
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    ListNode *l1 = makeListNode1(arr1, 3);
    ListNode *l2 = makeListNode1(arr2, 3);
    ListNode *r = mergeTwoLists(l1, l2);
    EXPECT_EQ (r->val, 1);
    EXPECT_EQ (r->next->val, 1);
    EXPECT_EQ (r->next->next->val, 2);
    EXPECT_EQ (r->next->next->next->val, 3);
    EXPECT_EQ (r->next->next->next->next->val, 4);
    EXPECT_EQ (r->next->next->next->next->next->val, 4);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
