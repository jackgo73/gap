#include "remove_duplicates.h"

int removeDuplicates(int* nums, int numsSize){
    if (numsSize <= 1) {
        return numsSize;
    }
    int slow = 1;
    for (int fast = 1; fast < numsSize; fast++) {
        if (nums[slow-1] != nums[fast]) {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}