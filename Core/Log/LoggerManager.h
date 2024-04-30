//LoggerManager.h

#ifndef START_APP_NAMESPACE_LOGGERMANAGER_H
#define START_APP_NAMESPACE_LOGGERMANAGER_H

#include <string>

#include "../Base/Pimpl.h"
#include "Logger.h"

namespace START_APP_NAMESPACE
{
    class LoggerManager {
        DECLARE_PRIVATE(LoggerManager)

    public:
        static LoggerManager& getInstance();

        std::shared_ptr<Logger> getLogger(const std::string& fileName);

    private:
        LoggerManager();
        LoggerManager(const LoggerManager&) = delete;
        LoggerManager& operator=(const LoggerManager&) = delete;
    };
}

#endif //START_APP_NAMESPACE_LOGGERMANAGER_H
