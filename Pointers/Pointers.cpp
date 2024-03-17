// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void addCounterR(int& total)
{
	std::cout << total << std::endl;
	total++;
	std::cout << total << std::endl;
}

void addCounterX(int* total)
{
	std::cout << total << std::endl;
	(*total)++;
	std::cout << total << std::endl;
}

void printPointerArithmetic()
{
	int foo = 1;

	// create a pointer
	int* foo_p = &foo;

	(*foo_p)++; // parathensis is required for order of precendence
				// foo is now 2


	// create a reference to foo
	int& foo_r = foo;

	// create a pointer to foo_p
	int** foo_pp = &foo_p;
}

int main()
{
	int total = 0;
	printf("Before: %d\n", total);
	addCounterR(total);
	printf("After: %d\n", total);
	printf("Before: %d\n", total);
	addCounterX(&total);
	printf("After: %d\n", total);
	printPointerArithmetic();

	int i = 420;
	printf("what is i: %d\n", i);
	int* pi = &i;
	printf("what is i: %d\n", i);
	*pi = 0;
	printf("what is i: %d\n", i);
}
