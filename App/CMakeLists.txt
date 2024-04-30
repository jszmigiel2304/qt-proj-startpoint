cmake_minimum_required(VERSION 3.16)


qt_add_executable(qt-proj-startpoint
    main.cpp
    App.h               App.cpp
    AppException.h      AppException.cpp
)

target_link_libraries(qt-proj-startpoint
    PRIVATE Qt6::Core
    PRIVATE Qt6::Gui
    PRIVATE Qt6::Quick
    PRIVATE Core
    PRIVATE Gui
)

target_include_directories(qt-proj-startpoint PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../Core)
target_include_directories(qt-proj-startpoint PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../Gui)
target_include_directories(qt-proj-startpoint PRIVATE "../Third/")
