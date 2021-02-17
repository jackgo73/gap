#include "gtest/gtest.h"
#include "p_00509_fib/fib.h"

TEST(p_00509_fib, basetest1) {
    Solution *s = new Solution();
    EXPECT_EQ (s->fib(4), 3);
    EXPECT_EQ (s->fib(3), 2);

    EXPECT_EQ (s->fib_memo(4), 3);
    EXPECT_EQ (s->fib_memo(3), 2);

    EXPECT_EQ (s->fib_dp(4), 3);
    EXPECT_EQ (s->fib_dp(3), 2);
}
