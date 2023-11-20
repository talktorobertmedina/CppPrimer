#include "Logger.h"
#include "LoggerSetting.h"
#include <iostream>

const char* Logger::LOG_LEVEL_STRING[] = {"INFO", "WARNING", "DEBUG", "ERROR", "SEVERE"};

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

