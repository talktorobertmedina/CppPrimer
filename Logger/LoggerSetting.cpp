#include "LoggerSetting.h"
#include <iostream>

const LoggerSetting LoggerSetting::parse(std::string logSettingData)
{
	// TODO: replace
	// a PropertyFile library should be made for files for parsing and return a map of properties
	return LoggerSetting();
}

LoggerSetting::LoggerSetting()
{

}

LoggerSetting::~LoggerSetting()
{

}

Logger::LOG_LEVEL LoggerSetting::getLevel()
{
	// TODO: replace
	return Logger::LOG_LEVEL::DEBUG;
}

bool LoggerSetting::setLevel(Logger::LOG_LEVEL level)
{
	// TODO: replace
	return false;
}
