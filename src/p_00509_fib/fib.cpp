//
// Created by 高铭杰 on 2021/1/23.
//
#include <vector>
#include "fib.h"

int Solution::fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int Solution::fib_memo(int n) {
    if (n < 1) return 0;
    std::vector<int> memo(n + 1, 0);
    return fib_memo_rescur(memo, n);
}

int Solution::fib_memo_rescur(std::vector<int> &memo, int n) {
    if (n == 1 || n == 2) return 1;
    if (memo[0] != 0) return memo[n];
    memo[n] = fib_memo_rescur(memo, n - 1) + fib_memo_rescur(memo, n - 2);
    return memo[n];
}

int Solution::fib_dp(int n) {
   if (n<1) return 0;
    if (n == 1 || n == 2) return 1;
    std::vector<int> dp(n+1 , 0);
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n ; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}


