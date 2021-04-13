#include "gtest/gtest.h"
#include "p_00022_generate_parenthesis/generate_parenthesis.h"

TEST(p_00022_generate_parenthesis, basetest1) {
    int returnSize = 0;
    generateParenthesis(3, &returnSize);
}
