// LoggerManagerPrivate.h

#ifndef START_APP_NAMESPACE_LOGGERMANAGERPRIVATE_H
#define START_APP_NAMESPACE_LOGGERMANAGERPRIVATE_H

#include <map>
#include <filesystem>

#include <QThread>

#include "LoggerManager.h"
#include "../Base/Definitions.h"

namespace START_APP_NAMESPACE
{
    class LoggerManager::LoggerManagerPrivate
    {
        friend class LoggerManager;
        typedef std::map<std::string, Logger::ShrPtr> LoggersMapsT;

        LoggersMapsT m_loggers;
        const std::filesystem::path m_logFilesDir{LOG_DIR};

        Logger::ShrPtr newLogger(const std::string &fileName);
    };
}

#endif //START_APP_NAMESPACE_LOGGERMANAGERPRIVATE_H
