
/*
* template:
* [Time] [Date] [Log_level] [Class_name] [Function_name] [Line_number] : This is a log message.
* 
* example log message:
* [21:43:00] [08/09/2023] [WARNING] [Logger] [parseLoggerSettingsFile] [This is a log message.]
* 
* P.S.
* log format message should be configurable and be able to edited at runtime
* add the ability to have rich text messages in this logger
* namespacing each file
* add tests
* format function should be outside log function
*/

#include <iostream>
#include <string>
#include "FileUtility.h"
#include "LoggerSetting.h"

int main(int argc, char** argv)
{
	std::string name("LoggerSettings.txt");
	std::string settingFileData = FileUtility::read(name);
	std::cout << settingFileData << std::endl;
	LoggerSetting loggerSetting = LoggerSetting::parse(settingFileData);
	Logger logger = Logger(loggerSetting);
	logger.log(Logger::LOG_LEVEL::INFO, "hello world");
	return 0;
}