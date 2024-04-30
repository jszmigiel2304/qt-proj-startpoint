// Logger.h

#ifndef START_APP_NAMESPACE_LOGGER_H
#define START_APP_NAMESPACE_LOGGER_H

#include <QObject>

#include <memory>

#include <spdlog/spdlog.h>

#include "../Base/Definitions.h"

namespace START_APP_NAMESPACE
{
    Q_NAMESPACE
    enum LogAction : EnumExtendedT {
        Core_LoggerCreate,
        Core_LoggerDestroyed,

        UndefinedAction
    };
    Q_ENUM_NS(LogAction)

    class LoggerManager;
    class LoggerManagerPrivate;
    class Logger {
        friend class LoggerManager;
        friend class LoggerManagerPrivate;

        Logger(const std::string& filePath);
        std::shared_ptr<spdlog::logger> m_logger;

    public:
        typedef std::shared_ptr<Logger> ShrPtr;
        typedef std::unique_ptr<Logger> UnqPtr;
        typedef spdlog::level::level_enum LogLevelT;

        std::shared_ptr<spdlog::logger> getLogger();
        void flush();

        void logAction(LogAction action, LogLevelT level);

    private:
        std::string actionDesc(LogAction action);
    };
}

#endif // START_APP_NAMESPACE_LOGGER_H
