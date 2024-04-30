cmake_minimum_required(VERSION 3.16)

project(Tests)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(TESTS_SOURCES
    main.cpp

    Module-Test.cpp
)

add_executable(Tests ${TESTS_SOURCES})

target_link_libraries(Tests
    PRIVATE ${GTEST_BOTH_LIBRARIES}
    PRIVATE Qt6::Core
    Core
    Gui
)

target_include_directories(Tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../Core)
