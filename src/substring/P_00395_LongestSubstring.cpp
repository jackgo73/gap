#include "P_00395_LongestSubstring.h"


int longestSubstring(char *s, int k) {
    if (*s == '\0' || k < 0) {
        return 0;
    }

    unsigned short slen = strlen(s);
    int maxlen = 0;

    for (int i = 0; i < slen; ++i) {
        unsigned short htab[26] = {0};
        for (int j = i; j < slen; ++j) {
            htab[s[j] - 'a'] += 1;
            int l;
            for (l = 0; l < 26; ++l) {
                if (htab[l] > 0 && htab[l] < k) break;
            }
            if (l == 26)
                maxlen = j - i + 1 > maxlen ? j - i + 1 : maxlen;
        }
    }
    return maxlen;
}
