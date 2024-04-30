// multiple_tests.cpp

#include <gtest/gtest.h>

// Example function to be tested
int add2(int a, int b) {
    return a + b;
}

// Test case to check addition with positive numbers
TEST(AddTest2, PositiveNumbers) {
    EXPECT_EQ(add2(2, 3), 5);
    EXPECT_EQ(add2(5, 7), 12);
    EXPECT_EQ(add2(10, 10), 20);
}

// Test case to check addition with negative numbers
TEST(AddTest2, NegativeNumbers) {
    EXPECT_EQ(add2(-2, -3), -5);
    EXPECT_EQ(add2(-5, -7), -12);
    EXPECT_EQ(add2(-10, -10), -20);
}

// Test case to check addition with a mix of positive and negative numbers
TEST(AddTest2, MixedNumbers) {
    EXPECT_EQ(add2(-2, 3), 1);
    EXPECT_EQ(add2(5, -7), -2);
    EXPECT_EQ(add2(-10, 5), -5);
}
