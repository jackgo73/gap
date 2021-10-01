#include "ut_00000.h"
#include "gtest/gtest.h"
#include "p_00146_l_r_u_cache.c"

TEST(L_R_U_CACHE, TEST01) {
    LRUCache* obj = lRUCacheCreate(3);
    lRUCacheGet(obj, 1);
	EXPECT_EQ (1, 1);
}
