#include "subarray_sum.h"

int Solution::subarraySumEasy(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> sum(n + 1);
    sum[0] = 0;
    for (int i = 0; i < n; i++)
        sum[i + 1] = sum[i] + nums[i];

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            // sum of nums[j..i-1]
            if (sum[i] - sum[j] == k)
                ans++;
    return ans;
}

int Solution::subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;
    int count = 0, pre = 0;
    for (auto &x:nums) {
        pre += x;
        if (mp.find(pre - k) != mp.end()) {
            count += mp[pre - k];
        }
        mp[pre]++;
    }
    return count;
}
