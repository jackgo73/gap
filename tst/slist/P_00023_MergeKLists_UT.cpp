#include "gtest/gtest.h"
#include "P_00023_MergeKLists.h"

TEST(P_00023_MergeKLists, TEST01) {
    const int rowCnt = 3;
    int r1[] = {3, 1, 4, 5};
    int r2[] = {3, 1, 3, 4};
    int r3[] = {2, 2, 6};

    int *r[rowCnt] = {r1, r2, r3};
    struct ListNode **l = makeListNode2(r, rowCnt);

    struct ListNode *res = mergeKLists(l, rowCnt);

    EXPECT_EQ (res->val, 1);
    EXPECT_EQ (res->next->val, 1);
    EXPECT_EQ (res->next->next->val, 2);
    EXPECT_EQ (res->next->next->next->val, 3);
    EXPECT_EQ (res->next->next->next->next->val, 4);

    free(res);
}

TEST(P_00023_MergeKLists, TEST02) {
    struct ListNode *r = NULL;
    struct ListNode **l = &r;

    struct ListNode *res = mergeKLists(l, 1);

    EXPECT_TRUE(res == NULL);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
