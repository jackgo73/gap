#ifndef P_00704_SEARCH
#define P_00704_SEARCH

#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int pivot, left = 0, right = nums.size() - 1;
        while (left <= right) {
            pivot = left + (right - left) / 2;
            if (nums[pivot] == target) return pivot;
            if (target < nums[pivot]) right = pivot - 1;
            else left = pivot + 1;
        }
        return -1;
    }

};


#endif //P_00704_SEARCH