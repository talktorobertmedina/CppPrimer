#include "Logger.h"
#include "LoggerSetting.h"
#include <iostream>

// these values must match the order of enums defined in the header since the index will map to the enum value
const char* Logger::LOG_LEVEL_STRING[] = {"INFO", "WARNING", "DEBUG", "ERROR", "SEVERE"};
const std::map<std::string, Logger::LOG_LEVEL> Logger::LOG_LEVEL_ENUM = {
	{Logger::LOG_LEVEL_STRING[Logger::LOG_LEVEL::INFO], Logger::LOG_LEVEL::INFO},
	{Logger::LOG_LEVEL_STRING[Logger::LOG_LEVEL::WARNING], Logger::LOG_LEVEL::WARNING},
	{Logger::LOG_LEVEL_STRING[Logger::LOG_LEVEL::DEBUG], Logger::LOG_LEVEL::DEBUG},
	{Logger::LOG_LEVEL_STRING[Logger::LOG_LEVEL::ERROR], Logger::LOG_LEVEL::ERROR},
	{Logger::LOG_LEVEL_STRING[Logger::LOG_LEVEL::SEVERE], Logger::LOG_LEVEL::SEVERE}
};

Logger::Logger()
{
}

Logger::Logger(const LoggerSetting& loggerSetting)
{
}

Logger::~Logger()
{
}

void Logger::log(Logger::LOG_LEVEL level, const std::string& message) const
{
	std::cout << "[" + std::string(LOG_LEVEL_STRING[level]) + "]: " + message << std::endl;
}

