#include "pch.h"
#include "PropertyParser.h"

TEST(PropertyParserTest, PropertyParserTest_parse) {
	PropertyParser::PropertyAnyMap empty;

	EXPECT_THROW({
		try
		{
			empty = PropertyParser::parse("");
		}
		catch (std::invalid_argument& ex)
		{
			EXPECT_STREQ("Cannot parse empty string", ex.what());
			throw;
		}
	}, std::invalid_argument);

	PropertyParser::PropertyAnyMap multipleKeys;
	multipleKeys = PropertyParser::parse("A=1\nB=2\nC=3\nD=4\nE=5\n");
	EXPECT_EQ(5, multipleKeys.size());
	EXPECT_EQ("1", multipleKeys["A"]);
	EXPECT_EQ("2", multipleKeys["B"]);
	EXPECT_EQ("3", multipleKeys["C"]);
	EXPECT_EQ("4", multipleKeys["D"]);
	EXPECT_EQ("5", multipleKeys["E"]);

  //EXPECT_EQ(1, 1);
  //EXPECT_TRUE(true);
}
