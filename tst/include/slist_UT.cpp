#include "gtest/gtest.h"
#include "benchmark/benchmark.h"
#include "slist.h"

TEST(slist, TEST01) {
    int arr[] = {1, 2, 3, 4, 5};
    ListNode *list1 = makeListNode1(arr, 5);
    EXPECT_EQ (1, 1);
}

TEST(slist, TEST02) {
    int arr[3][3] = {
            {1, 4, 5},
            {1, 3, 4},
            {2, 6}
    };
    ListNode **list2 = makeListNode2(arr, 3, 3);
    EXPECT_EQ (1, 1);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}