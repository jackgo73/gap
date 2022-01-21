#include "P_00003_LengthOfLongestSubstring.h"

using namespace std;

int Solution::lengthOfLongestSubstring(string s) {
    int left = 0, right = 0, ans = 0;
    int len = s.size();
    unordered_set<char> cset;

    for (left = 0; left < len; left++) {
        if (left != 0) {
            cset.erase(s[left - 1]);
        }
        while (right < len && !cset.count(s[right])) {
            cset.insert(s[right]);
            right += 1;
        }
        ans = max(ans, right - left);
    }

    return ans;// pwwkew
}


int lengthOfLongestSubstring(char *s) {
    int cset[127] = {0};
    int len = strlen(s);
    int right = 0, left, ans = 0;
    for (left = 0; left < len; ++left) {
        if (left != 0) {
            cset[s[left - 1]] = 0;
        }
        while (right < len && cset[s[right]] == 0) {
            cset[s[right]] = 1;
            right += 1;
        }
        ans = ans < right - left ? right - left : ans;
    }
    return ans;
}
