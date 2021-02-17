//
// Created by 高铭杰 on 2021/1/23.
//

#ifndef GAP_FIB_H
#define GAP_FIB_H


class Solution {
public:
    // 2^n
    int fib(int n);
    // n
    int fib_memo(int n);
    int fib_memo_rescur(std::vector<int> &memo, int n);
    // n
    int fib_dp(int n);
};


#endif //GAP_FIB_H
