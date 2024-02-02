#include <iostream>

void printSize(std::string type, size_t memory)
{
	std::cout << type << ":" << memory << std::endl;
}

void printArithmeticTypes()
{
	std::cout << "Arithmetic type memory sizes:" << std::endl;
	bool flag = false;
	printSize("bool", sizeof(flag));

	char letter;
	printSize("char", sizeof(letter));

	wchar_t wide_letter;
	printSize("wchar_t", sizeof(wide_letter));

	char16_t short_unicode;
	printSize("char16_t", sizeof(short_unicode));

	char32_t unicode;
	printSize("char32_t", sizeof(unicode));

	short short_number;
	printSize("short", sizeof(short_number));

	int number;
	printSize("int", sizeof(number));

	long long_number;
	printSize("long", sizeof(long_number));

	long long long_long_number;
	printSize("long long", sizeof(long_long_number));
}

void printFloatTypes()
{
	std::cout << "Floating-point type memory sizes:" << std::endl;
	float float_number;
	printSize("float", sizeof(float_number));

	double double_number;
	printSize("double", sizeof(double_number));

	long double long_double_number;
	printSize("long double", sizeof(long_double_number));
}

void printPrimitiveTypes()
{
	printArithmeticTypes();
	std::cout << std::endl;
	printFloatTypes();
}

int main()
{
	printPrimitiveTypes();
	return 0;
}