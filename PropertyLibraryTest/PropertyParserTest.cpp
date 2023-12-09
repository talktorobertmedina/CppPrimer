#include "pch.h"
#include "PropertyParser.h"

TEST(PropertyParserTest, PropertyParserTest_parse) {
	PropertyParser::PropertyAnyMap empty;
	empty = PropertyParser::parse("");
	
	EXPECT_EQ(0, empty.size());

	PropertyParser::PropertyAnyMap multipleKeys;
	multipleKeys = PropertyParser::parse("key=value");

  //EXPECT_EQ(1, 1);
  //EXPECT_TRUE(true);
}
