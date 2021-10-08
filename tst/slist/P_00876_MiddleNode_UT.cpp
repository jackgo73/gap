#include "gtest/gtest.h"
#include "P_00876_MiddleNode.h"

TEST(P_00876_MiddleNode, TEST01) {
    int arr[] = {1, 2, 3, 4, 5};
    ListNode *l = makeListNode1(arr, 5);
    ListNode *r = middleNode(l);
    EXPECT_EQ (r->val, 3);
}

TEST(P_00876_MiddleNode, TEST02) {
    int arr[] = {1, 2, 3, 4, 5, 6};
    ListNode *l = makeListNode1(arr, 6);
    ListNode *r = middleNode(l);
    EXPECT_EQ (r->val, 4);
}

TEST(P_00876_MiddleNode, TEST03) {
    int arr[] = {1, 2};
    ListNode *l = makeListNode1(arr, 2);
    ListNode *r = middleNode(l);
    EXPECT_EQ (r->val, 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
