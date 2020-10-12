#include "gtest/gtest.h"
#include "Randomize.h"
#include <vector>


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
    maxInt = 100;
    returnedInteger = Randomize::randomize(minInt, maxInt);
    EXPECT_TRUE(minInt <= returnedInteger && maxInt >= returnedInteger);
}


TEST(TestRandomize, randomizeFromIntegers) {
    std::vector<int> ints;

    // empty vector
    EXPECT_EQ(Randomize::randomize(ints), -1);

    // one element
    ints.push_back(1);
    EXPECT_EQ(Randomize::randomize(ints), 1);

    // two elements
    ints.push_back(2);
    int returnedInteger = Randomize::randomize(ints);
    EXPECT_TRUE(1 <= returnedInteger && 2 >= returnedInteger);

    // more elements
    ints.push_back(3);
    ints.push_back(5);
    ints.push_back(50);
    returnedInteger = Randomize::randomize(ints);
    EXPECT_TRUE(1 <= returnedInteger && 50 >= returnedInteger);
}
