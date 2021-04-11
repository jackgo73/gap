#ifndef P_00264_NTH_UGLY_NUMBER
#define P_00264_NTH_UGLY_NUMBER

#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> factors = {2, 3, 5};
        priority_queue<long, vector<long>, greater<>> heap;
        unordered_set<long> seen;
        heap.push(1L);
        seen.insert(1L);

        int ugly = 0;
        for (int i = 0; i < n; i++) {
            long curr = heap.top();
            heap.pop();
            ugly = (int) curr;
            for (int factor : factors) {
                long next = curr * factor;
                if (!seen.count(next)) {
                    seen.insert(next);
                    heap.push(next);
                }
            }
        }
        return ugly;
    };
}

#endif //P_00264_NTH_UGLY_NUMBER
