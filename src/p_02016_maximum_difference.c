#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <inttypes.h>

// 输入：nums = [7,1,5,4]   4
// 输入：nums = [9,4,3,2]   -1
// 输入：nums = [1,5,2,10]  9

//int maximumDifference(int *nums, int numsSize) {
//    int res = -1;
//    int tmp;
//    for (int i = 0; i < numsSize - 1; ++i) {
//        for (int j = i + 1; j < numsSize; ++j) {
//            if (nums[i] < nums[j]) {
//                tmp = nums[j] - nums[i];
//                res = res > tmp ? res : tmp;
//            }
//        }
//    }
//    return res;
//}

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int maximumDifference(int *nums, int numsSize) {
    int dp[numsSize];
    int res = -1;
    dp[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        dp[i] = MIN(dp[i - 1], nums[i]);
    }
    for (int i = 1; i < numsSize; i++) {
        res = MAX(res, nums[i] - dp[i]);
    }
    return res > 0 ? res : -1;
}