// test_main.cpp

#include <gtest/gtest.h>

#include <QCoreApplication>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    QCoreApplication app(argc, argv);
    return RUN_ALL_TESTS();
}
