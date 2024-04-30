// Logger.h

#ifndef START_APP_NAMESPACE_LOGGER_H
#define START_APP_NAMESPACE_LOGGER_H

#include <memory>

#include <spdlog/spdlog.h>

namespace START_APP_NAMESPACE
{
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

        std::shared_ptr<spdlog::logger> getLogger();

    };
}

#endif // START_APP_NAMESPACE_LOGGER_H
