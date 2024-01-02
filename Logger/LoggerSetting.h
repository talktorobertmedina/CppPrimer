#pragma once

#include<string>
#include "Logger.h"

class LoggerSetting
{
public:
	enum MESSAGE_TEMPLATE_FLAGS : unsigned long
	{
		PRINT_TIME =		1 << 0, 
		PRINT_LOG_LEVEL =	1 << 1, 
		PRINT_CLASS_NAME =	1 << 2, 
		PRINT_FUNC_NAME =	1 << 3, 
		PRINT_LINE_COUNT =	1 << 4, 
		PRINT_MESSAGE =		1 << 5
	};

	static const LoggerSetting parse(std::string logSettingData);
	LoggerSetting();
	virtual ~LoggerSetting();
	Logger::LOG_LEVEL getLevel();
	bool setLevel(Logger::LOG_LEVEL level);
	bool setMessageTemplate(std::string messageTemplateFormat);
private:
	Logger::LOG_LEVEL m_level;
	// LOG_MESSAGE_TEMPLATE = [% t][% l][% cn][% fn][% lc] : [% msg]

};
