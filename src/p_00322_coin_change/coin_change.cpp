#include "coin_change.h"

int Solution::coinChange(vector<int> &coins, int amount) {
    return coinChangeRescur(coins, amount);
}

// 定义：要凑出金额 target，至少要 coinChangeDp(coins, target) 个硬币
int Solution::coinChangeRescur(vector<int> &coins, int target) {
    if (target == 0) return 0;
    if (target < 0) return -1;

    int n = INT_MAX;
    for (int coin : coins) {
        int subproblem = coinChangeRescur(coins, target - coin);
        // 子问题无解，跳过
        if (subproblem == -1) continue;
        // 做选择，选择需要硬币最少的那个结果
        n = min(n, 1 + coinChangeRescur(coins, target - coin));
    }
    return (n != INT_MAX) ? n : -1;
}

int Solution::coinChangeMemo(vector<int> &coins, int amount) {
    if (amount < 1) return 0;
    vector<int> memo(amount + 1, 0);
    return coinChangeMemoRescur(memo, coins, amount);
}

int Solution::coinChangeMemoRescur(vector<int> &memo, vector<int> &coins, int target) {
    if (target == 0) return 0;
    if (target < 0) return -1;
    if (memo[target] != 0) return memo[target];

    int n = INT_MAX;
    for (int coin : coins) {
        int subproblem = coinChangeMemoRescur(memo, coins, target - coin);
        // 子问题无解，跳过
        if (subproblem == -1) continue;
        // 做选择，选择需要硬币最少的那个结果
        n = min(n, 1 + subproblem);
    }
    memo[target] = (n != INT_MAX) ? n : -1;
    return memo[target];
}

