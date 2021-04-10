#include "gtest/gtest.h"
#include "c_02021_spring_store_water/store_water.h"

TEST(c_02021_spring_store_water, basetest1) {
    int bucket[] = {1, 3};
    int vat[] = {6, 8};
    EXPECT_EQ (storeWater(bucket, 2, vat, 2), 4);
}

TEST(c_02021_spring_store_water, basetest2) {
    int bucket[] = {9, 0, 1};
    int vat[] = {0, 2, 2};
    EXPECT_EQ (storeWater(bucket, 3, vat, 3), 3);
}

TEST(c_02021_spring_store_water, basetest3) {
    int bucket[] = {0, 0, 1};
    int vat[] = {0, 2, 2};
    EXPECT_EQ (storeWater(bucket, 3, vat, 3), 3);
}

TEST(c_02021_spring_store_water, basetest4) {
    int bucket[] = {0, 55, 1};
    int vat[] = {0, 2, 33};
    EXPECT_EQ (storeWater(bucket, 3, vat, 3), 11);
}
