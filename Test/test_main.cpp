// test_main.cpp

#include <gtest/gtest.h>

// Example function to be tested
int add(int a, int b) {
    return a + b;
}

// A test case
TEST(AddTest, PositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5);
}

// Another test case
TEST(AddTest, NegativeNumbers) {
    EXPECT_EQ(add(-2, -3), -5);
}

// Main function to run the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
