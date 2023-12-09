#include "pch.h"
#include "PropertyParser.h"
#include <iostream>

const PropertyParser::PropertyAnyMap PropertyParser::parse(std::string data)
{
	size_t startIndex = 0;
	size_t endItr = 0;
	size_t dataSize = data.size();
	char
	// https://en.cppreference.com/w/cpp/string/basic_string/find
	for (size_t itr = 0; itr <= dataSize; ++itr)
	{
		if (*itr == '=')
		{
			std::distance(startItr, itr);
		}
	}

	return PropertyParser::PropertyAnyMap();
}
