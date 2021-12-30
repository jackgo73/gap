
#include "gtest/gtest.h"
#include "benchmark/benchmark.h"
#include "P_00001_TwoSum.cpp"

std::vector<int> input1 = {2, 7, 11, 15};
int input2 = 9;
std::vector<int> expect1 = {0, 1};

TEST(P_00001_TwoSum_1, TEST01) {
    auto *p00001TwoSum = new P_00001_TwoSum_1();
    std::vector<int> output = p00001TwoSum->twoSum(input1, input2);

    ASSERT_EQ(output.size(), expect1.size());
    for (int i = 0; i < expect1.size(); ++i) {
        EXPECT_EQ(expect1[i], output[i]) << "Vectors x and y differ at index " << i;
    }
}

TEST(P_00001_TwoSum_2, TEST01) {
    auto *p00001TwoSum = new P_00001_TwoSum_2();
    std::vector<int> output = p00001TwoSum->twoSum(input1, input2);

    ASSERT_EQ(output.size(), expect1.size());
    for (int i = 0; i < expect1.size(); ++i) {
        EXPECT_EQ(expect1[i], output[i]) << "Vectors x and y differ at index " << i;
    }
}

static void BM_P_00001_TwoSum_2(benchmark::State &state) {
    for (auto _ : state) {
        for (uint32_t i = int64_t(state.range(0)); i > 0; i--) {
            auto *p00001TwoSum = new P_00001_TwoSum_2();
            std::vector<int> output = p00001TwoSum->twoSum(input1, input2);
        }
    }
}

static void BM_P_00001_TwoSum_1(benchmark::State &state) {
    for (auto _ : state) {
        for (uint32_t i = int64_t(state.range(0)); i > 0; i--) {
            auto *p00001TwoSum = new P_00001_TwoSum_1();
            std::vector<int> output = p00001TwoSum->twoSum(input1, input2);
        }
    }
}

BENCHMARK(BM_P_00001_TwoSum_2)->Arg(1)->Arg(10);
BENCHMARK(BM_P_00001_TwoSum_1)->Arg(1)->Arg(10);


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    return RUN_ALL_TESTS();
}