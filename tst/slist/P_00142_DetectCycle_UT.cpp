#include "gtest/gtest.h"
#include "P_00142_DetectCycle.h"

TEST(P_00142_DetectCycle, TEST01) {
    int arr[] = {3, 2, 0, -4};
    ListNode *l = makeListNode1(arr, 4);
    l->next->next->next->next = l->next;

    ListNode *r = detectCycle(l);
    EXPECT_EQ (1, 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
