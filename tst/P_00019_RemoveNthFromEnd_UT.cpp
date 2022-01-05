#include "gtest/gtest.h"
#include "benchmark/benchmark.h"
#include "P_00019_RemoveNthFromEnd.cpp"

auto *solution = new Solution();

TEST(P_00019_RemoveNthFromEnd, TEST01) {
    ListNode *l1_5 = new ListNode(5, nullptr);
    ListNode *l1_4 = new ListNode(4, l1_5);
    ListNode *l1_3 = new ListNode(3, l1_4);
    ListNode *l1_2 = new ListNode(2, l1_3);
    ListNode *l1_1 = new ListNode(1, l1_2);
    auto *r = solution->removeNthFromEnd(l1_1, 2);
    EXPECT_EQ (r->next->next->next->next->val, 5);
}

TEST(P_00019_RemoveNthFromEnd, TEST02) {
    ListNode *l1_1 = new ListNode(1, nullptr);
    auto *r = solution->removeNthFromEnd(l1_1, 1);
    EXPECT_EQ (r->val, 5);
}

static void BM_P_00019_RemoveNthFromEnd(benchmark::State &state) {
    for (auto _ : state) {
        for (uint32_t i = int64_t(state.range(0)); i > 0; i--) {
            // solution->...
        }
    }
}

// BENCHMARK(BM_P_00019_RemoveNthFromEnd)->Arg(1)->Arg(10);


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    return RUN_ALL_TESTS();
}
