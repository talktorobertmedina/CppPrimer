#include "LoggerSetting.h"
#include "PropertyParser.h"
#include <iostream>

const LoggerSetting LoggerSetting::parse(std::string logSettingData)
{
	// TODO: replace
	// a PropertyFile library should be made for files for parsing and return a map of properties
	LoggerSetting loggerSetting;
	PropertyParser::PropertyAnyMap propertyMap = PropertyParser::parse(logSettingData);
	std::string logLevelString = propertyMap.at("LOG_LEVEL");
	Logger::LOG_LEVEL logLevelEnum = Logger::LOG_LEVEL_ENUM.at(logLevelString);
	loggerSetting.setLevel(logLevelEnum);
	return loggerSetting;
}

LoggerSetting::LoggerSetting()
{

}

LoggerSetting::~LoggerSetting()
{

}

Logger::LOG_LEVEL LoggerSetting::getLevel()
{
	return m_level;
}

bool LoggerSetting::setLevel(Logger::LOG_LEVEL level)
{
	m_level = level;
	return true;
}
