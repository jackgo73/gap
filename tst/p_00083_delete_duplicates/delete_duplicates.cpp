#include "gtest/gtest.h"
#include "p_00083_delete_duplicates/delete_duplicates.h"

TEST(p_00083_delete_duplicates, basetest1) {
    ListNode input = {1, new ListNode{1, new ListNode{2, nullptr}}};
    deleteDuplicates(&input);

    EXPECT_EQ (input.next->val, 2);
}
