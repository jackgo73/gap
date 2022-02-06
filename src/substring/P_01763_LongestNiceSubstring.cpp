#include "P_01763_LongestNiceSubstring.h"

bool isLower(char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    return false;
}

char *longestNiceSubstring(char *s) {
    char *p = s;
    unsigned n = strlen(p);
    int maxPos = 0;
    int maxLen = 0;

    for (int i = 0; i < n; ++i) {
        unsigned lowerBM = 0;
        unsigned upperBM = 0;
        for (int j = i; j < n; ++j) {
            if (isLower(s[j])) {
                lowerBM |= 1u << (s[j] - 'a');
            } else {
                upperBM |= 1u << (s[j] - 'A');
            }
            if (lowerBM == upperBM && j - i + 1 > maxLen) {
                maxPos = i;
                maxLen = j - i + 1;
            }

            if (lowerBM == upperBM && j - i + 1 > maxLen) {
                maxPos = i;
                maxLen = j - i + 1;
            }
        }
    }
    char *ans = (char *) malloc(sizeof(char) * (maxLen + 1));
    strncpy(ans, s + maxPos, maxLen);
    ans[maxLen] = '\0';
    return ans;
}