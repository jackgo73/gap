#ifndef P_00278_FIRST_BAD_VERSION
#define P_00278_FIRST_BAD_VERSION

#include <vector>
#include <cstdlib>
#include <cstdio>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool isBadVersion(int version);

using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
        int pivot, left, right;
        left = 1;
        right = n;
        while (left < right) {
            pivot = left + (right - left) / 2;
            if (isBadVersion(pivot)) {
                right = pivot;
            } else {
                left = pivot + 1;
            }

        }
        return left;
    }
};


#endif //P_00278_FIRST_BAD_VERSION