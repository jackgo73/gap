

#include <string.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int longestSubStr(char *word1, char *word2, int m, int n) {
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    char chRow, chCol;
    for (int i = 1; i < m + 1; ++i) {
        chRow = word1[i - 1];
        for (int j = 1; j < n + 1; ++j) {
            chCol = word2[j - 1];
            if (chCol == chRow) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = MAX(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[m][n];
}

int minDistance(char *word1, char *word2) {
    int m = strlen(word1), n = strlen(word2);
    int overlap = longestSubStr(word1, word2, m, n);
    return m + n - overlap - overlap;
}