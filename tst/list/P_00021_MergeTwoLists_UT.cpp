#include "gtest/gtest.h"
#include "benchmark/benchmark.h"
#include "list/P_00021_MergeTwoLists.cpp"

auto *solution = new Solution();

TEST(P_00021_MergeTwoLists, TEST01) {
    ListNode l1_3(4, nullptr);
    ListNode l1_2(2, &l1_3);
    ListNode l1_1(1, &l1_2);
    ListNode l2_3(4, nullptr);
    ListNode l2_2(3, &l2_3);
    ListNode l2_1(1, &l2_2);
    ListNode *r = solution->mergeTwoLists(&l1_1, &l2_1);

    EXPECT_EQ (r->val, 1);
    EXPECT_EQ (r->next->val, 1);
    EXPECT_EQ (r->next->next->val, 2);
    EXPECT_EQ (r->next->next->next->val, 3);
    EXPECT_EQ (r->next->next->next->next->val, 4);
    EXPECT_EQ (r->next->next->next->next->next->val, 4);
}

static void BM_P_00021_MergeTwoLists(benchmark::State &state) {
    for (auto _ : state) {
        for (uint32_t i = int64_t(state.range(0)); i > 0; i--) {
            // solution->...
        }
    }
}

// BENCHMARK(BM_P_00021_MergeTwoLists)->Arg(1)->Arg(10);


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    return RUN_ALL_TESTS();
}
