//LoggingDevice.cpp
#include "LoggingDevice.h"

#include "../Log/LoggerManager.h"

using namespace START_APP_NAMESPACE;

LoggingDevice::LoggingDevice(const std::string &logFile)
{
    m_logger = LoggerManager::getInstance().getLogger(logFile);
}
