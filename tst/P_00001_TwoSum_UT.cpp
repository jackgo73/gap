#include "gtest/gtest.h"
#include "benchmark/benchmark.h"
#include "P_00001_TwoSum.c"

TEST(P_00001_TwoSum, TEST01) {

    EXPECT_EQ (1, 1);
}

static void BM_P_00001_TwoSum(benchmark::State &state) {
    for (auto _ : state) {
        for (uint32_t i = int64_t(state.range(0)); i > 0; i--) {
            // solution->...
        }
    }
}

// BENCHMARK(BM_P_00001_TwoSum)->Arg(1)->Arg(10);


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    return RUN_ALL_TESTS();
}
