#!/bin/bash

if [[ $# != 2 ]] ; then
echo "USAGE: $0 number title "
echo " e.g.: $0 4 FindMedianSortedArrays"
exit 1;
fi

number=$(printf "%05d\n" ${1})
# title=$(echo "${2}" | sed -E 's/([A-Z])/_\1/g' | sed -E 's/^_//g' | tr 'A-Z' 'a-z')
title=$(echo "${2}")
utitle=$(echo "${title}" | tr "[a-z]" "[A-Z]")

problem_name="P_${number}_${title}"

src_name="${problem_name}.c"
tst_name="${problem_name}_UT.cpp"

echo "src file name: " ${src_name}
echo "tst file name: " ${tst_name}

touch src/${src_name}
cat << EOF > src/${src_name}
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <inttypes.h>

EOF

touch tst/${tst_name}
cat << EOF > tst/"${tst_name}"
#include "gtest/gtest.h"
#include "benchmark/benchmark.h"
#include "${src_name}"

TEST(${problem_name}, TEST01) {

    EXPECT_EQ (1, 1);
}

static void BM_${problem_name}(benchmark::State &state) {
    for (auto _ : state) {
        for (uint32_t i = int64_t(state.range(0)); i > 0; i--) {
            // solution->...
        }
    }
}

// BENCHMARK(BM_${problem_name})->Arg(1)->Arg(10);


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    return RUN_ALL_TESTS();
}
EOF
