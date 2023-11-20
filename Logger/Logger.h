#pragma once

#include <string>

class LoggerSetting;
class Logger
{
public:
	enum LOG_LEVEL {
		INFO, WARNING, DEBUG, ERROR, SEVERE
	};
	static const char* LOG_LEVEL_STRING[];

	Logger();
	Logger(const LoggerSetting& loggerSetting);
	~Logger();
	void log(Logger::LOG_LEVEL level, const std::string& message) const;
private:
	Logger::LOG_LEVEL m_level;
};

