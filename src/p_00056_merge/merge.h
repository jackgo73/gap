#ifndef P_00056_MERGE
#define P_00056_MERGE

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty()) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            } else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;

    }
};

#endif //P_00056_MERGE
