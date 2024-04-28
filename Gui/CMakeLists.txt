add_library(GuiModule STATIC
    Gui.h               Gui.cpp
    GuiException.h      GuiException.cpp
)

find_package(Qt6 COMPONENTS Core Gui Quick REQUIRED)

qt_add_resources(RESOURCES
    qml.qrc
)

target_sources(GuiModule
    PRIVATE ${RESOURCES}
)

target_link_libraries(GuiModule
    PRIVATE Qt6::Core
    PRIVATE Qt6::Gui
    PRIVATE Qt6::Quick
    PRIVATE CoreModule
)

target_include_directories(GuiModule PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../Core)
