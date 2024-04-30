//LoggerManagerPrivate.cpp
#include "LoggerManagerPrivate.h"

#include "../CoreException.h"

using namespace START_APP_NAMESPACE;

Logger::ShrPtr LoggerManager::LoggerManagerPrivate::newLogger(const std::string &fileName)
{
    try {
        std::string _filePath = m_logFilesDir.string() + fileName;
        //auto [iter, succ] = m_loggers.emplace( std::make_pair(fileName, new Logger(_filePath) )  );
        auto [iter, succ] = m_loggers.emplace(
            std::make_pair(fileName, std::shared_ptr<Logger>( new Logger(_filePath), [](Logger* ptr) {
                               ptr->logAction(Logger::Core_LoggerDestroyed, Logger::LogLevelT::info);
                delete ptr;
            }) )
        );
        if(!succ) {
            return nullptr;
        }

        iter->second->logAction(Logger::Core_LoggerCreate, Logger::LogLevelT::info);
        return iter->second;
    } catch ( const std::bad_alloc& e ) {
        throw CoreException("bad_alloc exception in LoggerManager");
    } catch ( ... ) {
        throw CoreException("spdlog (?) exception in LoggerManager");
    }
}
