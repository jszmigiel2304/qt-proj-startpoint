cmake_minimum_required(VERSION 3.16)

project(Tests)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(TESTS_SOURCES
    test_main.cpp
    test_main_2.cpp
)

add_executable(Tests ${TESTS_SOURCES})

target_link_libraries(Tests ${GTEST_BOTH_LIBRARIES} Core Gui)
