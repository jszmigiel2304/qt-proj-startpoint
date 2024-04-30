add_library( Core STATIC
    Base/Exception.h            Base/Exception.cpp
    Base/Definitions.h
    Base/Pimpl.h

    Interfaces/IModule.h

    Log/Logger.h                Log/Logger.cpp

    Module/Module.h             Module/Module.cpp
    Module/ModulePrivate.h      Module/ModulePrivate.cpp
    Module/ModuleException.h    Module/ModuleException.cpp
)

find_package(Qt6 COMPONENTS Core REQUIRED)

target_link_libraries( Core
    PRIVATE Qt6::Core
)
