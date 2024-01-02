#include "LoggerSetting.h"
#include "PropertyParser.h"
#include <iostream>
#include <bitset>

const std::string LoggerSetting::PRINT_TIME_STRING = "%t";
const std::string LoggerSetting::PRINT_LOG_LEVEL_STRING = "%l";
const std::string LoggerSetting::PRINT_CLASS_NAME_STRING = "%cn";
const std::string LoggerSetting::PRINT_FUNC_NAME_STRING = "%fn";
const std::string LoggerSetting::PRINT_LINE_COUNT_STRING = "%lc";
const std::string LoggerSetting::PRINT_MESSAGE_STRING = "%msg";

const LoggerSetting LoggerSetting::parse(std::string logSettingData)
{
	LoggerSetting loggerSetting;
	PropertyParser::PropertyAnyMap propertyMap = PropertyParser::parse(logSettingData);
	std::string logLevelString = propertyMap.at("LOG_LEVEL");
	std::string logMessageTemplateString = propertyMap.at("LOG_MESSAGE_TEMPLATE");
	Logger::LOG_LEVEL logLevelEnum = Logger::LOG_LEVEL_ENUM.at(logLevelString);
	loggerSetting.setLevel(logLevelEnum);
	loggerSetting.setMessageTemplate(logMessageTemplateString);
	return loggerSetting;
}

LoggerSetting::LoggerSetting() :
	m_level(Logger::ERROR),
	m_flags(0x00)
{

}

LoggerSetting::~LoggerSetting()
{

}

[[nodiscard]] Logger::LOG_LEVEL LoggerSetting::getLevel() const
{
	return m_level;
}

bool LoggerSetting::setLevel(Logger::LOG_LEVEL level)
{
	m_level = level;
	return true;
}

bool LoggerSetting::setMessageTemplate(std::string messageTemplateFormat)
{
	if (messageTemplateFormat.find(LoggerSetting::PRINT_TIME_STRING))
	{
		m_flags |= LoggerSetting::MESSAGE_TEMPLATE_FLAGS::PRINT_TIME;
	}
	if (messageTemplateFormat.find(LoggerSetting::PRINT_LOG_LEVEL_STRING))
	{
		m_flags |= LoggerSetting::MESSAGE_TEMPLATE_FLAGS::PRINT_LOG_LEVEL;
	}
	if (messageTemplateFormat.find(LoggerSetting::PRINT_CLASS_NAME_STRING))
	{
		m_flags |= LoggerSetting::MESSAGE_TEMPLATE_FLAGS::PRINT_CLASS_NAME;
	}
	if (messageTemplateFormat.find(LoggerSetting::PRINT_FUNC_NAME_STRING))
	{
		m_flags |= LoggerSetting::MESSAGE_TEMPLATE_FLAGS::PRINT_FUNC_NAME;
	}
	if (messageTemplateFormat.find(LoggerSetting::PRINT_LINE_COUNT_STRING))
	{
		m_flags |= LoggerSetting::MESSAGE_TEMPLATE_FLAGS::PRINT_LINE_COUNT;
	}
	if (messageTemplateFormat.find(LoggerSetting::PRINT_MESSAGE_STRING))
	{
		m_flags |= LoggerSetting::MESSAGE_TEMPLATE_FLAGS::PRINT_MESSAGE;
	}

	m_messageTemplate = messageTemplateFormat;

	return true;
}

[[nodiscard]] std::string LoggerSetting::getMessageTemplate() const
{
	return m_messageTemplate;
}

[[nodiscard]] uint8_t LoggerSetting::getFlags() const
{
	return m_flags;
}
