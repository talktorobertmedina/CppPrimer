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
	[[nodiscard]] Logger::LOG_LEVEL getLevel() const;
	bool setLevel(Logger::LOG_LEVEL level);
	[[nodiscard]] std::string getMessageTemplate() const;
	bool setMessageTemplate(std::string messageTemplateFormat);
	[[nodiscard]] uint8_t getFlags() const;
private:
	static const std::string PRINT_TIME_STRING;
	static const std::string PRINT_LOG_LEVEL_STRING;
	static const std::string PRINT_CLASS_NAME_STRING;
	static const std::string PRINT_FUNC_NAME_STRING;
	static const std::string PRINT_LINE_COUNT_STRING;
	static const std::string PRINT_MESSAGE_STRING;

	Logger::LOG_LEVEL m_level;
	std::uint8_t m_flags;
	std::string m_messageTemplate;
};
