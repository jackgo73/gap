#include "gtest/gtest.h"
#include "benchmark/benchmark.h"
#include "list/P_00023_MergeKLists.cpp"

auto *solution = new Solution();

TEST(P_00023_MergeKLists, TEST01) {
    ListNode *l1_3 = new ListNode(5, nullptr);
    ListNode *l1_2 = new ListNode(4, l1_3);
    ListNode *l1_1 = new ListNode(1, l1_2);

    ListNode *l2_3 = new ListNode(4, nullptr);
    ListNode *l2_2 = new ListNode(3, l2_3);
    ListNode *l2_1 = new ListNode(1, l2_2);

    ListNode *l3_2 = new ListNode(6, nullptr);
    ListNode *l3_1 = new ListNode(2, l3_2);

    std::vector<ListNode *> input = {l1_1, l2_1, l3_1};
    solution->mergeKLists(input);

    EXPECT_EQ (1, 1);
}

static void BM_P_00023_MergeKLists(benchmark::State &state) {
    for (auto _ : state) {
        for (uint32_t i = int64_t(state.range(0)); i > 0; i--) {
            // solution->...
        }
    }
}

// BENCHMARK(BM_P_00023_MergeKLists)->Arg(1)->Arg(10);


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    return RUN_ALL_TESTS();
}
