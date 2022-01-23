#include "P_00567_CheckInclusion.h"



bool checkInclusion(char *s1, char *s2) {
    int l = 0, r = 0;
    int s1len = strlen(s1), s2len = strlen(s2);
    int need[26] = {0}, win[26] = {0};
    int s1Keysize = 0;

    for (int i = 0; i < s1len; i++) {
        if (need[s1[i] - 'a'] == 0) s1Keysize++;
        need[s1[i] - 'a']++;
    }

    int found = 0;
    // [l, r)
    while (r < s2len) {
        char rc = s2[r++] - 'a';
        if (need[rc] != 0) {
            win[rc]++;
            if (need[rc] == win[rc]) found++;
        }
        while (r - l >= s1len) {
            if (found == s1Keysize) {
                return true;
            }
            char lc = s2[l++] - 'a';
            if (need[lc] != 0) {
                if (need[lc] == win[lc]) found--;
                win[lc]--;
            }
        }
    }
    return false;
}