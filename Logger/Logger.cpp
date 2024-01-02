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

const void Logger::replace_first(std::string& source, const std::string& matcher, const std::string& replacement)
{
	size_t pos = source.find(matcher);
	if (pos == std::string::npos)
	{
		return;
	}

	source.replace(pos, matcher.length(), replacement);
}

Logger::Logger(const LoggerSetting& loggerSetting) :
	m_loggerSettings(loggerSetting)
{
}

Logger::~Logger()
{
}

void Logger::log(Logger::LOG_LEVEL level, const std::string& message) const
{
	std::string buildMessage = m_loggerSettings.getMessageTemplate();
	if (m_loggerSettings.getFlags() & LoggerSetting::MESSAGE_TEMPLATE_FLAGS::PRINT_TIME)
	{
		// replace_first(buildMessage, "%t", "00:00:00");
	}
	if (m_loggerSettings.getFlags() & LoggerSetting::MESSAGE_TEMPLATE_FLAGS::PRINT_LOG_LEVEL)
	{
		replace_first(buildMessage, "%l", std::string(LOG_LEVEL_STRING[level]));
	}
	if (m_loggerSettings.getFlags() & LoggerSetting::MESSAGE_TEMPLATE_FLAGS::PRINT_CLASS_NAME)
	{
	}
	if (m_loggerSettings.getFlags() & LoggerSetting::MESSAGE_TEMPLATE_FLAGS::PRINT_FUNC_NAME)
	{
	}
	if (m_loggerSettings.getFlags() & LoggerSetting::MESSAGE_TEMPLATE_FLAGS::PRINT_LINE_COUNT)
	{
	}
	if (m_loggerSettings.getFlags() & LoggerSetting::MESSAGE_TEMPLATE_FLAGS::PRINT_MESSAGE)
	{
		replace_first(buildMessage, "%msg", message);
	}

	printf("%s\n", buildMessage.c_str());
}
