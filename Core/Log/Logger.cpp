// Logger.cpp
#include "Logger.h"

#include <map>

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>

#include "../Base/Base.h"

using namespace START_APP_NAMESPACE;


Logger::Logger(const std::string& filePath)
{
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(filePath,  5 * 1024 * 1024, 5);
    m_logger = std::make_shared<spdlog::logger>("logger", spdlog::sinks_init_list{console_sink, file_sink});
    spdlog::register_logger(m_logger);
}

std::shared_ptr<spdlog::logger> Logger::getLogger()
{
    return m_logger;
}

void Logger::logAction(LogAction action, LogLevelT level)
{
    if(!m_logger) {
        return;
    }

    std::string _actionStr = Base::toString(action);
    std::string _actionDesc = actionDesc(action);

    switch(level) {
    case LogLevelT::trace:      { m_logger->trace("[{}][{}]", _actionStr, _actionDesc);       break; }
    case LogLevelT::debug:      { m_logger->debug("[{}][{}]", _actionStr, _actionDesc);       break; }
    case LogLevelT::info:       { m_logger->info("[{}][{}]", _actionStr, _actionDesc);        break; }
    case LogLevelT::warn:       { m_logger->warn("[{}][{}]", _actionStr, _actionDesc);        break; }
    case LogLevelT::err:        { m_logger->error("[{}][{}]", _actionStr, _actionDesc);       break; }
    case LogLevelT::critical:   { m_logger->critical("[{}][{}]", _actionStr, _actionDesc);    break; }
    case LogLevelT::off:        { return; }
    case LogLevelT::n_levels:   { return; }
    }
    m_logger->flush();
}

std::string Logger::actionDesc(LogAction action)
{
    static const std::map<LogAction, const std::string> map = {
        {   Core_LoggerCreate,           "Logger created."               },
        {   Core_LoggerDestroyed,        "Logger destroyed."             },
        {   UndefinedAction,             "Undefined action to log."      },
    };
    std::string _ret = map.contains(action) ? map.at(action) : map.at(UndefinedAction);
    return map.contains(action) ? map.at(action) : map.at(UndefinedAction);
}

void Logger::flush()
{
    if(!m_logger) {
        return;
    }

    m_logger->flush();
}
