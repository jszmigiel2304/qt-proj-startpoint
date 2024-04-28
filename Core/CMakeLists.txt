add_library( CoreModule STATIC
    Base/Exception.h            Base/Exception.cpp

    Log/Logger.h                Log/Logger.cpp
)

find_package(Qt6 COMPONENTS Core REQUIRED)
target_link_libraries( CoreModule
    PRIVATE Qt6::Core
)
