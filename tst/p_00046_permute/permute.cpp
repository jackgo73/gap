#include "gtest/gtest.h"
#include "p_00046_permute/permute.h"


TEST(p_00046_permute, basetest2)

{
    int intput[] = {1, 2, 3};
    int returnSize = 0;
    int **returnColumnSizes = (int **)malloc(6 * sizeof(int*));

    int expect[6][3] = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    int **output;
    output = permute(intput, 3, &returnSize, returnColumnSizes);
}

