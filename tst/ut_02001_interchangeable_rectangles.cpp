#include "gtest/gtest.h"
#include "p_02001_interchangeable_rectangles.c"

TEST(INTERCHANGEABLE_RECTANGLES, TEST01) {
    int **rectangles;
    int rectanglesSize = 4;
    int rectanglesColSize = 2;
    rectangles = (int **) malloc(sizeof(int *) * rectanglesSize);
    for (int i = 0; i < rectanglesSize; ++i) {
        rectangles[i] = (int *) malloc(sizeof(int) * 2);
    }
    rectangles[0][0] = 4;
    rectangles[0][1] = 8;
    rectangles[1][0] = 3;
    rectangles[1][1] = 6;
    rectangles[2][0] = 10;
    rectangles[2][1] = 20;
    rectangles[3][0] = 15;
    rectangles[3][1] = 30;

    EXPECT_EQ (interchangeableRectangles(rectangles, rectanglesSize, &rectanglesColSize), 6);
}
