
#include "stdlib.h"

int cmp(const void *d1, const void *d2) {
    return *(double *) d1 > *(double *) d2;
}

long long interchangeableRectangles(int **rectangles, int rectanglesSize, int *rectanglesColSize) {
    double res[rectanglesSize];
    for (int i = 0; i < rectanglesSize; ++i) {
        res[i] = (double) rectangles[i][0] / rectangles[i][1];
    }
    qsort(res, rectanglesSize, sizeof(double), cmp);

    long long sum = 0;
    long long count = 0;
    for (int i = 0; i < rectanglesSize - 1; i++) {
        if (res[i] == res[i + 1]) {
            count++;
        } else {
            sum += count * (count + 1) / 2;
            count = 0;
        }
    }
    if (count > 0) {
        sum += count * (count + 1) / 2;
    }
    return sum;
}