#pragma once

#include <map>
#include <string>
#include <any>

class PropertyParser
{
public:
	static const std::map<std::string, std::any> parse(std::string data);
};

