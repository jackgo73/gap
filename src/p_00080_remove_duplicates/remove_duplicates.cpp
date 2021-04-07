#include "remove_duplicates.h"

// nums = [1,1,1,2,2,3]
//         ^ ^
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return numsSize;
    }
    int slow = 2, fast = 2;
    while (fast < numsSize) {
        if (nums[slow - 2] != nums[fast]) {
            nums[slow] = nums[fast];
            ++slow;
        }
        ++fast;
    }
    return slow;
}

// 输入：nums = [1,1,1,2,2,3]
// 输出：5, nums = [1,1,2,2,3]
int removeDuplicates1(int* nums, int numsSize) {
    if (numsSize < 3) {
        return numsSize;
    }
    int slow = 2, fast = 2;
    for (; fast < numsSize; fast++) {
        if (nums[slow - 2] != nums[fast]) {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}




















