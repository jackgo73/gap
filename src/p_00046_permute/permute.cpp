#include "permute.h"

using namespace std;

vector<vector<int>> Solution::permute(vector<int> &nums) {
    list<int> track;
    backtrack(nums, track);
    return res;
}

void Solution::backtrack(vector<int> &nums, list<int> track) {
    if (track.size() == nums.size()) {
        vector<int> r(track.begin(), track.end());
        res.push_back(r);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        bool found = (find(track.begin(), track.end(), nums[i]) != track.end());
        if (found) continue;
        track.push_back(nums[i]);
        backtrack(nums, track);
        track.pop_back();
    }
}

int **res;
int resN;

void dfs(int *nums, int numsSize, int *path, int pathN, bool *used) {
    if (pathN == numsSize) {
        res[resN] = (int *) malloc(numsSize * sizeof(int));
        memcpy(res[resN++], path, numsSize * sizeof(int));
        return;
    }
    // （1）对于回溯数的每一个节点，开始做选择，如果前面选过了，不再选。
    // （2）path路径数组记录当前选择了谁
    // （3）向下递归选下一个
    // （4）撤销当前的选择，当前的选择是给下一层使用的，不应该影响当前层
    for (int i = 0; i < numsSize; ++i) {
        if (used[i] == true) {
            continue;
        }
        path[pathN] = nums[i];
        used[i] = true;
        dfs(nums, numsSize, path, pathN + 1, used);
        used[i] = false;
    }
}

int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    int n = 1;
    for (int i = 1; i <= numsSize; ++i) {
        n *= i;
    }
    res = (int **) malloc(n * sizeof(int *));
    resN = 0;

    bool *used = (bool *) malloc(numsSize * sizeof(bool));
    memset(used, 0, numsSize * sizeof(bool));

    int *path = (int *) malloc(numsSize * sizeof(int));
    int pathN = 0;
    dfs(nums, numsSize, path, pathN, used);

    *returnSize = n;
    returnColumnSizes[0] = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        (*returnColumnSizes)[i] = numsSize;
    }
    return res;
}

