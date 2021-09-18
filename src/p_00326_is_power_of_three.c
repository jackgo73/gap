

#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

bool isPowerOfThree(int n) {
    while (n && n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}