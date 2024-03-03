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
	std::cout << std::endl;
}

void printNonBoolToBoolCast()
{
	// non-bool arithmetic to bool
	int x = 6;
	bool flag = x;

	printf("Non-bool arithmetic type to bool type\n");

	if (flag)
	{
		printf("non-zero numbers are true\n");
		flag = 0;
	}
	if (!flag)
	{
		printf("zero number is false\n");
		flag = -1;
	}
	if (flag)
	{
		printf("negative numbers are true\n");
	}
}

void printBoolToNonBool()
{
	printf("Bool type to non-bool arithmetic type\n");
	printf("True is equal to %d\n", true);
	printf("False is equal to %d\n", false);
}

void printFloatToInt()
{
	printf("Float type to int type\n");
	int x = 1.101f;
	printf("1.10f cast to int is %d\n", x);
	x = 0.0f;
	printf("0.0f cast to int is %d\n", x);
	x = -1.10f;
	printf("-1.10f cast to int is %d\n", x);
}

void printIntToFloat()
{
	printf("Int type to float type\n");
	float x = 1;
	printf("1 cast to float is %f\n", x);
	x = 3;
	printf("3 cast to float is %f\n", x);
	x = -1;
	printf("-1 cast to float is %f\n", x);
}

void printTypeConversions()
{
	printNonBoolToBoolCast();
	std::cout << std::endl;
	printBoolToNonBool();
	std::cout << std::endl;
	printFloatToInt();
	std::cout << std::endl;
	printIntToFloat();
	std::cout << std::endl;
}

void brainTeaser()
{
	std::cout << "Section 2.1.2: Exercise 2.3" << std::endl;
	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl; // 32
	std::cout << u - u2 << std::endl; // a large number
	int i = 10, i2 = 42;
	std::cout << i2 - i << std::endl; // 32
	std::cout << i - i2 << std::endl; // -32
	std::cout << i - u << std::endl; // 0
	std::cout << u - i << std::endl; // 0
	std::cout << std::endl;
}

void literals()
{
	std::cout << "Literals:" << std::endl;
	std::cout << "Exercise 2.5" << std::endl;
	std::cout << "SECTION A" << std::endl;
	std::cout << 'a' << std::endl; // type is char literal
	std::cout << L'a' << std::endl; // type is wide character, 97
	std::cout << "a" << std::endl; // type is string
	std::cout << L"a" << std::endl; // type is string wide character, a very large number
	std::cout << "SECTION B" << std::endl;
	std::cout << 10 << std::endl; // type is decimal
	std::cout << 10u << std::endl; // type is unsigned decimal
	std::cout << 10L << std::endl; // type is long
	std::cout << 10uL << std::endl; // type is unsigned long
	std::cout << 012 << std::endl; // type is octal
	std::cout << 0xC << std::endl; // type is hexadecimal
	std::cout << "SECTION C" << std::endl;
	std::cout << 3.14 << std::endl; // type is double
	std::cout << 3.14f << std::endl; // type is float
	std::cout << 3.14L << std::endl; // type is long double
	std::cout << "SECTION D" << std::endl;
	std::cout << 10 << std::endl; // type is decimal
	std::cout << 10u << std::endl; // type is unsigned int
	std::cout << 10. << std::endl; // type is double
	std::cout << 10e-2 << std::endl; // type is double
	std::cout << "Exercise 2.7" << std::endl;
	std::cout << "Who goes with F\145rgus?\012" << std::endl; // type is string with value Who goes with Faergus?\n
	std::cout << 3.14e1L << std::endl; // type is long double
	std::cout << 1024.f << std::endl; // type is float
	std::cout << 10e-2 << std::endl; // type is long double
	std::cout << "Exercise 2.8" << std::endl;
	std::cout << "2\155" << std::endl;
	std::cout << "2\011\155\012" << std::endl;
}

int main()
{
	printPrimitiveTypes();
	printTypeConversions();
	brainTeaser();
	literals();
	return 0;
}
