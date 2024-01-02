#pragma once

#include <map>
#include <string>

class __declspec(dllexport) PropertyParser
{
public:
	typedef std::map<std::string, std::string> PropertyAnyMap;
	static const PropertyAnyMap parse(std::string data);
private:
	static const char LINE_ENDING_DELIMITER;
	static const bool isKeyIdentiferValid(std::string identifier);
	static const bool isKeyValueValid(std::string keyValue);
};
