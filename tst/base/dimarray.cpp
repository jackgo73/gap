#include "gtest/gtest.h"
#include "benchmark/benchmark.h"

TEST(dim, TEST01) {
//    int dim1[] = {1, 2, 3, 4, 5};
//    int dim2[3][3] = {{1, 4, 5},
//                      {1, 3, 4},
//                      {2, 6}};
//    int *p_dim2 = (int *) dim2;

    int **p = (int **) malloc(sizeof(int *) * 10);
    for (int i = 0; i < 10; i++) {
        p[i] = (int *) malloc(sizeof(int) * 5);
    }
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}