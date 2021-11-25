#include "gtest/gtest.h"
#include "benchmark/benchmark.h"
#include "slist.h"

TEST(slist, TEST01) {
    int arr[] = {1, 2, 3, 4, 5};

    ListNode *l = makeListNode1(arr, 5);

    EXPECT_EQ (l->val, 1);
    EXPECT_EQ (l->next->val, 2);
    EXPECT_EQ (l->next->next->val, 3);
}

TEST(slist, TEST02) {
    const int rowCnt = 3;
    int r1[] = {3, 1, 4, 5};
    int r2[] = {3, 1, 3, 4};
    int r3[] = {2, 2, 6};

    int *r[rowCnt] = {r1, r2, r3};
    struct ListNode **l = makeListNode2(r, rowCnt);
    EXPECT_EQ (l[0]->val, 1);
    EXPECT_EQ (l[0]->next->val, 4);
    EXPECT_EQ (l[0]->next->next->val, 5);
    EXPECT_EQ (l[1]->val, 1);
    EXPECT_EQ (l[1]->next->val, 3);
    EXPECT_EQ (l[1]->next->next->val, 4);
    EXPECT_EQ (l[2]->val, 2);
    EXPECT_EQ (l[2]->next->val, 6);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}