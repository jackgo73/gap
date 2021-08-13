#ifndef P_00035_SEARCH_INSERT
#define P_00035_SEARCH_INSERT

#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, ans = n;
        while (left <= right) {
            int mid = ((right - left) >> 1) + left;
            if (target <= nums[mid]) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};


#endif //P_00035_SEARCH_INSERT