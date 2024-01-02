#pragma once

#include <string>
#include <map>

class LoggerSetting;
class Logger
{
public:
	enum LOG_LEVEL
	{
		INFO, WARNING, DEBUG, ERROR, SEVERE
	};
	static const char* LOG_LEVEL_STRING[];
	static const std::map<std::string, LOG_LEVEL> LOG_LEVEL_ENUM;

	Logger(const LoggerSetting& loggerSetting);
	~Logger();
	void log(LOG_LEVEL level, const std::string& message) const;
private:
	const LoggerSetting& m_loggerSettings;
	static const void replace_first(std::string& source, const std::string& matcher, const std::string& replacement);
};
