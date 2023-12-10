#include "pch.h"
#include "PropertyParser.h"
#include <iostream>

const PropertyParser::PropertyAnyMap PropertyParser::parse(std::string data)
{
	const size_t NEWLINE_CHARACTER = 1;
	size_t dataSize = data.size();
	if (dataSize <= 0)
	{
		throw std::invalid_argument("Cannot parse empty string");
	}

	PropertyParser::PropertyAnyMap propertyMap;
	for (size_t lineStartIndex = 0, lineEndIndex = data.find('\n', lineStartIndex); lineEndIndex < std::string::npos; lineStartIndex = lineEndIndex + NEWLINE_CHARACTER, lineEndIndex = data.find('\n', lineStartIndex))
	{
		size_t delimiterIndex = data.find('=', lineStartIndex);
		std::string keyName = data.substr(lineStartIndex, delimiterIndex - lineStartIndex);
		std::string mappedValue = data.substr(delimiterIndex + 1, lineEndIndex - delimiterIndex - NEWLINE_CHARACTER);
		propertyMap[keyName] = mappedValue;
	}

	return propertyMap;
}
