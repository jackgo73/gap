#include "gtest/gtest.h"
#include "p_00043_multiply.c"

TEST(MULTIPLY, TEST01) {
    char *num1 = strdup("123");
    char *num2 = strdup("456");
    EXPECT_STRCASEEQ(multiply(num1, num2), "56088");
}
