#include "gtest/gtest.h"
#include "benchmark/benchmark.h"
#include "P_00141_HasCycle.cpp"

auto *solution = new Solution();

TEST(P_00141_HasCycle, TEST01) {

    EXPECT_EQ (1, 1);
}

static void BM_P_00141_HasCycle(benchmark::State &state) {
    for (auto _ : state) {
        for (uint32_t i = int64_t(state.range(0)); i > 0; i--) {
            // solution->...
        }
    }
}

// BENCHMARK(BM_P_00141_HasCycle)->Arg(1)->Arg(10);


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    return RUN_ALL_TESTS();
}
