#include "letter_combinations.h"

#include "stdlib.h"
#include "string.h"
#include "math.h"

static char *g_keys[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
static int g_keys_size[10] = {1, 1, 3, 3, 3, 3, 3, 4, 3, 4};

char **ans;
unsigned ans_idx;
unsigned digits_size;

void dfs(char *digits, int digit_idx, char *path, int path_idx) {
    if (digit_idx == digits_size) {
        ans[ans_idx] = (char *) malloc((digits_size + 1) * sizeof(char));;
        strcpy(ans[ans_idx++], path);
        return;
    }
    char *letters = g_keys[digits[digit_idx] - '0'];
    for (size_t i = 0; i < strlen(letters); i++) {
        path[path_idx++] = letters[i];
        path[path_idx] = 0;
        dfs(digits, digit_idx + 1, path, path_idx);
        path[--path_idx] = 0;
    }
}

char **letterCombinations(char *digits, int *returnSize) {
    digits_size = strlen(digits);
    if (digits_size == 0) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 1;
    for (int i = 0; i < digits_size; i++) {
        *returnSize = (*returnSize) * g_keys_size[digits[i] - '0'];
    }

    ans = (char **) malloc((*returnSize) * sizeof(char *));
    ans_idx = 0;

    char *path = (char *) malloc((digits_size + 1) * sizeof(char));

    dfs(digits, 0, path, 0);
    return ans;
}
