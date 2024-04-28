cmake_minimum_required(VERSION 3.16)

project(qt-proj-startpoint VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Gui Quick REQUIRED)
qt_standard_project_setup(REQUIRES 6.5)

add_subdirectory(App)
add_subdirectory(Core)
add_subdirectory(Gui)
