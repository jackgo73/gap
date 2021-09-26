#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

void help(const char *s, int N, int left, int right, int *start, int *len) {
    while (left >= 0 && right < N && s[left] == s[right])
        left--, right++;
    if (right - left - 1 > *len) {
        *start = left + 1;
        *len = right - left - 1;
    }
}

char *longestPalindrome(char *s) {
    int N = (int) strlen(s), start = 0, len = 0;
    for (int i = 0; i < N; i++)
        help(s, N, i - 1, i + 1, &start, &len);
    for (int i = 0; i < N; i++)
        help(s, N, i, i + 1, &start, &len);
    s[start + len] = '\0';
    return s + start;
}
