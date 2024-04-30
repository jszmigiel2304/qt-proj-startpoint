// LoggingDevice.h
#ifndef START_APP_NAMESPACE_LOGGINGDEVICE_H
#define START_APP_NAMESPACE_LOGGINGDEVICE_H

#include "../Log/Logger.h"

#define LOGGER          m_logger->getLogger()
#define LOGGER_FLUSH    m_logger->getLogger()->flush();

namespace START_APP_NAMESPACE
{
    class LoggingDevice
    {
    public:
        LoggingDevice(const std::string& logFile);

    protected:
        Logger::ShrPtr m_logger{nullptr};
    };
}

#endif //START_APP_NAMESPACE_LOGGINGDEVICE_H
