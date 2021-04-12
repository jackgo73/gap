#include "permute.h"

#include "stdlib.h"
#include "memory"

int **res;
int resN;

void dfs(int *selection, int sNum, int *path, int pIdx, bool *isUsed) {
    if (sNum == pIdx) {
        res[resN] = (int *) malloc(sNum * sizeof(int));
        memcpy(res[resN++], path, sNum * sizeof(int));
        return;
    }
    for (int i = 0; i < sNum; i++) {
        if (isUsed[i]) {
            continue;
        }
        path[pIdx] = selection[i];
        isUsed[i] = true;
        dfs(selection, sNum, path, pIdx + 1, isUsed);
        isUsed[i] = false;
    }
}

int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    (*returnSize) = 1;
    for (int i = 1; i <= numsSize; i++) {
        (*returnSize) *= i;
    }
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = numsSize;
    }


    res = (int **) malloc((*returnSize) * sizeof(int *));
    resN = 0;

    bool *isUsed = (bool *) calloc(numsSize, sizeof(bool));
    int *path = (int *) malloc(numsSize * sizeof(int));

    dfs(nums, numsSize, path, 0, isUsed);
    return res;
}

