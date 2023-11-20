#pragma once

#include<string>
#include "Logger.h"

class LoggerSetting
{
public:
	static const LoggerSetting parse(std::string logSettingData);
	LoggerSetting();
	virtual ~LoggerSetting();
	Logger::LOG_LEVEL getLevel();
	bool setLevel(Logger::LOG_LEVEL level);
private:
	Logger::LOG_LEVEL m_level;
};
