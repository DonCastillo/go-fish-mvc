#include "gtest/gtest.h"
#include "Randomize.h"


TEST(TestRandomize, randomizeFromRange) {
    // minimum integer: -1
    // maximum integer: -2
    EXPECT_EQ(Randomize::randomize(-1, -2), -1);

    // minimum integer: 10
    // maximum integer: 0
    EXPECT_EQ(Randomize::randomize(10, 0), 10);

    // minimum integer: -15
    // maximum integer: -15
    EXPECT_EQ(Randomize::randomize(-15, -15), -15);

    // minimum integer: 15
    // maximum integer: 15
    EXPECT_EQ(Randomize::randomize(15, 15), 15);

    // minimum integer: 14
    // maximum integer: 15
    int minInt = 14, maxInt = 15;
    int returnedInteger = Randomize::randomize(minInt, maxInt);
    EXPECT_TRUE(minInt <= returnedInteger && maxInt >= returnedInteger);

    minInt = 0;
    maxInt = 100
    returnedInteger = Randomize::randomize(minInt, maxInt);
    EXPECT_TRUE(minInt <= returnedInteger && maxInt >= returnedInteger);
}
