#pragma once

#include <map>
#include <string>
#include <any>

class __declspec(dllexport) PropertyParser
{
public:
	typedef std::map<std::string, std::any> PropertyAnyMap;
	static const PropertyAnyMap parse(std::string data);
private:

};

