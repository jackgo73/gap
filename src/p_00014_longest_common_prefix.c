
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *longestCommonPrefix(char **strs, int strsSize) {
    if (strsSize <= 1) {
        return strs[0];
    }
    int len = (int) strlen(strs[0]);
    for (int col = 0; col < len; ++col) {
        for (int row = 0; row < strsSize - 1; ++row) {
            if (strs[row][col] != strs[row + 1][col]) {
                strs[0][col] = '\0';
                col = len;
                break;
            }
        }
    }
    return strs[0];
}