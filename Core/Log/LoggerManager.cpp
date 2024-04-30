// LoggerManager.cpp

#include "LoggerManager.h"
#include "LoggerManagerPrivate.h"

#include "../CoreException.h"

using namespace START_APP_NAMESPACE;
namespace fs = std::filesystem;

LoggerManager &LoggerManager::getInstance()
{
    static LoggerManager _instance;
    return _instance;
}

std::shared_ptr<Logger> LoggerManager::getLogger(const std::string& fileName)
{
    auto it = PRIVATE(m_loggers).find(fileName);
    if (it != PRIVATE(m_loggers).end()) {
        return it->second;
    }

    return PRIVATE(newLogger(fileName));
}

LoggerManager::LoggerManager()
{
    INITIALIZE_PRIVATE(LoggerManager)

    if( !fs::exists( PRIVATE(m_logFilesDir) ) ) {
        try {
            fs::create_directory( PRIVATE(m_logFilesDir) );
        } catch (const fs::filesystem_error& e) {
            throw CoreException(QString("filesystem exception when creating dir: []") +
                                QString::fromStdString(PRIVATE(m_logFilesDir.string())));
        }
    }
}
