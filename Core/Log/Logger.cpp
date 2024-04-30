// Logger.cpp
#include "Logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>


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
