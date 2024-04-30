add_library( Core STATIC
    Base/Base.h                 Base/Base.cpp
    Base/Exception.h            Base/Exception.cpp
    Base/Definitions.h
    Base/Pimpl.h
    Base/Concepts.h

    Interfaces/IModule.h

    Log/Logger.h                Log/Logger.cpp
    Log/LoggerManager.h         Log/LoggerManager.cpp
    Log/LoggerManagerPrivate.h  Log/LoggerManagerPrivate.cpp
    Log/LoggingDevice.h         Log/LoggingDevice.cpp

    Module/Module.h             Module/Module.cpp
    Module/ModulePrivate.h      Module/ModulePrivate.cpp
    Module/ModuleException.h    Module/ModuleException.cpp

    CoreException.h             CoreException.cpp
)

find_package(Qt6 COMPONENTS Core REQUIRED)

target_link_libraries( Core
    PRIVATE Qt6::Core
)

target_include_directories(Core PRIVATE "../Third/")
