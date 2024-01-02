#include "pch.h"
#include "PropertyParser.h"

TEST(PropertyParserTest, PropertyParserTest_parse) {
	PropertyParser::PropertyAnyMap empty;

	// Test for empty string
	EXPECT_THROW({
		try
		{
			empty = PropertyParser::parse("");
		}
		catch (std::invalid_argument& ex)
		{
			EXPECT_STREQ("Source string cannot be empty", ex.what());
			throw;
		}
	}, std::invalid_argument);

	// Test for missing line ending
	EXPECT_THROW({
		try
		{
			empty = PropertyParser::parse("A=1");
		}
		catch (std::invalid_argument& ex)
		{
			EXPECT_STREQ("Source string must end with a valid line ending delimiter \\n", ex.what());
			throw;
		}
	}, std::invalid_argument);

	// Test for missing equal symbol in key-value pair line
	EXPECT_THROW({
		try
		{
			empty = PropertyParser::parse("A=1\nB=2\nC-1\n");
		}
		catch (std::invalid_argument& ex)
		{
			EXPECT_STREQ("Failed to find a valid key-value pair on line: 3", ex.what());
			throw;
		}
	}, std::invalid_argument);

	// Test for missing key symbol in key-value pair line
	EXPECT_THROW({
		try
		{
			empty = PropertyParser::parse("A=1\nB=2\n=1\n");
		}
		catch (std::invalid_argument& ex)
		{
			EXPECT_STREQ("Failed to find a valid key-value pair on line: 3", ex.what());
			throw;
		}
	}, std::invalid_argument);

	// Test for missing value symbol in key-value pair line
	EXPECT_THROW({
		try
		{
			empty = PropertyParser::parse("A=1\nB=2\nC=\n");
		}
		catch (std::invalid_argument& ex)
		{
			EXPECT_STREQ("Failed to find a valid key-value pair on line: 3", ex.what());
			throw;
		}
	}, std::invalid_argument);

	// TODO: create test cases to test for valid key identifiers and value identifiers

	PropertyParser::PropertyAnyMap multipleKeys;
	multipleKeys = PropertyParser::parse("A=1\nB=2\nC=3\nD=4\nE=5\n");
	EXPECT_EQ(5, multipleKeys.size());
	EXPECT_EQ("1", multipleKeys["A"]);
	EXPECT_EQ("2", multipleKeys["B"]);
	EXPECT_EQ("3", multipleKeys["C"]);
	EXPECT_EQ("4", multipleKeys["D"]);
	EXPECT_EQ("5", multipleKeys["E"]);
}
