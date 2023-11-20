#include <string>
#include <iostream>

int main()
{
	std::string name;
	std::cout << "Enter your name: ";
	std::getline(std::cin, name);
	std::cout << "Hi " << name << "!" << std::endl;
}