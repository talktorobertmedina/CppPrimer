#include "pch.h"
#include "PropertyParser.h"
#include <iostream>

const char PropertyParser::LINE_ENDING_DELIMITER = '\n';

const PropertyParser::PropertyAnyMap PropertyParser::parse(std::string data)
{
	const size_t NEWLINE_CHARACTER = 1;

	size_t dataSize = data.size();
	if (dataSize <= 0)
	{
		throw std::invalid_argument("Source string cannot be empty");
	}

	if (data.back() != PropertyParser::LINE_ENDING_DELIMITER)
	{
		throw std::invalid_argument("Source string must end with a valid line ending delimiter \\n");
	}

	PropertyParser::PropertyAnyMap propertyMap;
	for (size_t lineStartIndex = 0, lineEndIndex = data.find(PropertyParser::LINE_ENDING_DELIMITER, lineStartIndex), lineNumber = 1;
		lineEndIndex < std::string::npos; 
		lineStartIndex = lineEndIndex + NEWLINE_CHARACTER, lineEndIndex = data.find(PropertyParser::LINE_ENDING_DELIMITER, lineStartIndex), lineNumber++)
	{
		size_t delimiterIndex = data.find('=', lineStartIndex);

		if (delimiterIndex == -1)
		{
			throw std::invalid_argument("Failed to find a valid key-value pair on line: " + std::to_string(lineNumber));
		}

		//printf("AA: LINE: %zd, DELIM: %zd, START_I: %zd, END_I: %zd\n", lineNumber, delimiterIndex, lineStartIndex, lineEndIndex);
		std::string keyName = data.substr(lineStartIndex, delimiterIndex - lineStartIndex);
		std::string mappedValue = data.substr(delimiterIndex + 1, lineEndIndex - delimiterIndex - NEWLINE_CHARACTER);

		if (keyName.empty() || mappedValue.empty())
		{
			throw std::invalid_argument("Failed to find a valid key-value pair on line: " + std::to_string(lineNumber));
		}

		propertyMap[keyName] = mappedValue;
	}

	return propertyMap;
}
