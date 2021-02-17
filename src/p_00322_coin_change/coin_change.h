#ifndef P_00322_COIN_CHANGE
#define P_00322_COIN_CHANGE

#include <vector>

using namespace std;

class Solution {
public:
    // n^k
    int coinChange(vector<int> &coins, int amount);

    int coinChangeRescur(vector<int> &coins, int n);

    int coinChangeMemo(vector<int> &coins, int amount);

    int coinChangeMemoRescur(vector<int> &memo, vector<int> &coins, int target);
};


#endif //P_00322_COIN_CHANGE
