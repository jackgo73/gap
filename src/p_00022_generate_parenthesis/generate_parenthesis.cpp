#include "generate_parenthesis.h"

#include "stdlib.h"
#include "memory.h"

void dfs(int n, int left, int right, char *path, int depth, char **result, int *result_idx) {
    if (2 * n == depth) {
        result[*result_idx] = (char *) malloc((2 * n + 1) * sizeof(char));
        result[*result_idx][2 * n] = '\0';
        strcpy(result[(*result_idx)++], path);
        return;
    }
    if (left < n) {
        path[depth] = '(';
        dfs(n, left + 1, right, path, depth + 1, result, result_idx);
    }
    if (right < left) {
        path[depth] = ')';
        dfs(n, left, right + 1, path, depth + 1, result, result_idx);
    }
}

char **generateParenthesis(int n, int *returnSize) {
    char **result = (char **) malloc(sizeof(char *) * 4000);
    *returnSize = 0;
    char *path = (char *) calloc(n * 2 + 1, sizeof(char));
    dfs(n, 0, 0, path, 0, result, returnSize);
    return result;
}