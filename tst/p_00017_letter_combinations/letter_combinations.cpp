#include "gtest/gtest.h"
#include "p_00017_letter_combinations/letter_combinations.h"

TEST(p_00017_letter_combinations, basetest1) {
    char *input = "23";
    int returnSize = 0;
    letterCombinations(input, &returnSize);
}
