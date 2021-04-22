#include "gtest/gtest.h"
#include "utils.h"
#include "p_00002_add_two_numbers/add_two_numbers.h"

TEST(p_00002_add_two_numbers, basetest1) {
    int a1[] = {2,4,3};
    int a2[] = {5,6,4};
    int a3[] = {7,0,8};
    struct ListNode *l1 = arrayToList(a1, 3);
    struct ListNode *l2 = arrayToList(a2, 3);
    struct ListNode *l3 = arrayToList(a3, 3);
    struct ListNode *res = addTwoNumbers(l1, l2);

    EXPECT_EQ (res->val, l3->val);
    EXPECT_EQ (res->next->val, l3->next->val);
    EXPECT_EQ (res->next->next->val, l3->next->next->val);

}
