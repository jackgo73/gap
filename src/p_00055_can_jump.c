#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <inttypes.h>

// 输入：nums = [2,3,1,1,4]  true
// 输入：nums = [3,2,1,0,4]  false

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

bool canJump(int *nums, int numsSize) {
    int dp[numsSize];
    dp[0] = nums[0];
    if (dp[0] <= 0) {
        return numsSize == 1;
    }
    for (int i = 1; i < numsSize; ++i) {
        dp[i] = MAX(dp[i - 1] - 1, nums[i]);
        if (dp[i] <= 0 && i < numsSize - 1) return false;
    }
    return true;
}
