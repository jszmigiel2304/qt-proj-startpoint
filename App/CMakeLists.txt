add_executable(appqt-proj-startpoint
    App.h               App.cpp
    AppException.h      AppException.cpp
)

find_package(Qt6 COMPONENTS Core Gui Quick REQUIRED)

target_sources(appqt-proj-startpoint
    PRIVATE main.cpp
)

target_link_libraries(appqt-proj-startpoint
    PRIVATE Qt6::Core
    PRIVATE Qt6::Gui
    PRIVATE Qt6::Quick
    PRIVATE CoreModule
    PRIVATE GuiModule
)

target_include_directories(appqt-proj-startpoint PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../Core)
target_include_directories(appqt-proj-startpoint PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../Gui)
