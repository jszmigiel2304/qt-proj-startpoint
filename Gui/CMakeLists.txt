qt_add_qml_module(Gui
    URI Gui
    VERSION 1.0
    SOURCES
        Gui.h               Gui.cpp
        GuiException.h      GuiException.cpp
    QML_FILES
        Qml/Main.qml
)

target_link_libraries(Gui
    PRIVATE Qt6::Core
    PRIVATE Qt6::Gui
    PRIVATE Qt6::Quick
    PRIVATE Core
)

target_include_directories(Gui PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../Core)
