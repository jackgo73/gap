#include "permute.h"

vector<vector<int>> Solution::permute(vector<int> &nums) {
    list<int> track;
    backtrack(nums, track);
    return res;
}

void Solution::backtrack(vector<int> &nums, list<int> track) {
    if (track.size() == nums.size()) {
        vector<int> r(track.begin(), track.end());
        res.push_back(r);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        bool found = (find(track.begin(), track.end(), nums[i]) != track.end());
        if (found) continue;
        track.push_back(nums[i]);
        backtrack(nums, track);
        track.pop_back();
    }
}
