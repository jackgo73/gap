#include "gtest/gtest.h"
#include "p_00322_coin_change/coin_change.h"

struct Inputs {
    int amount;
    vector<int> coins;
    int result;
};

TEST(p_00322_coin_change, basetest1) {
    Inputs inputs[3] = {
            {11, {1, 2, 5}, 3},
            {16, {1, 3, 6}, 4},
    };
    Solution *s = new Solution();
    for (Inputs input : inputs) {
        EXPECT_EQ (s->coinChange(input.coins, input.amount), input.result);
        EXPECT_EQ (s->coinChangeMemo(input.coins, input.amount), input.result);
    }
}
