#pragma once

#include <map>
#include <string>

class __declspec(dllexport) PropertyParser
{
public:
	typedef std::map<std::string, std::string> PropertyAnyMap;
	static const PropertyAnyMap parse(std::string data);
private:

};
