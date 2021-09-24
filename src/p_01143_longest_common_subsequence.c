

#include <string.h>
#include <math.h>

/*   0 1 2 3 4 5 6
     _ b d c a b a
 0 - 0 0 0 0 0 0 0
 1 a 0 0 0 0 1
 2 b 0
 3 c 0
 4 b 0
 5 d 0
 6 a 0
 7 b 0
*/
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
int longestCommonSubsequence(char *text1, char *text2) {
    unsigned int m = strlen(text1), n = strlen(text2);
    unsigned int dp[m + 1][n + 1];
    char chRow, chCol;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < m + 1; ++i) {
        chRow = text1[i - 1];
        for (int j = 1; j < n + 1; ++j) {
            chCol = text2[j - 1];
            if (chRow == chCol) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = MAX(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return (int)dp[m][n];
}