#include "utils/colors.h"
#include "Whatever.hpp"
#include <iostream>

static void swapTests() {
	std::cout << C_YELLOW << "RUNNING SWAPTESTS() FOR STRINGS" << C_RESET << std::endl;
	{

		std::string str1("hello");
		std::string str2("world");
		std::cout << C_CYAN << "str1: " << C_RESET << str1 << " " << C_CYAN << "str2: " << C_RESET << str2 << std::endl;
		std::cout << C_MAGENTA << "swaping!" << C_RESET << std::endl;
		::swap(str1, str2);
		std::cout << C_CYAN << "str1: " << C_RESET << str1 << " " << C_CYAN << "str2: " << C_RESET << str2 << std::endl;
	}
	std::cout << C_YELLOW << "RUNNING SWAPTESTS() FOR INTEGERS" << C_RESET << std::endl;
	{

		int int1 = 42;
		int int2 = 24;
		std::cout << C_CYAN << "int1: " << C_RESET << int1 << " " << C_CYAN << "int2: " << C_RESET << int2 << std::endl;
		std::cout << C_MAGENTA << "swaping!" << C_RESET << std::endl;
		::swap(int1, int2);
		std::cout << C_CYAN << "int1: " << C_RESET << int1 << " " << C_CYAN << "int2: " << C_RESET << int2 << std::endl;
	}
	std::cout << C_YELLOW << "ENDING SWAPTESTS()" << C_RESET << std::endl << std::endl;
}

static void minTests() {
	std::cout << C_YELLOW << "RUNNING MINTESTS() FOR STRINGS" << C_RESET << std::endl;
	{

		std::string str1("hello");
		std::string str2("world");
		std::cout << C_CYAN << "str1: " << C_RESET << str1 << " " << C_CYAN << "str2: " << C_RESET << str2 << std::endl;
		std::cout << C_MAGENTA << "Returning: " << ::min(str1, str2) << C_RESET << std::endl;
	}
	std::cout << C_YELLOW << "RUNNING MINTESTS() FOR INTEGERS" << C_RESET << std::endl;
	{

		int int1 = 42;
		int int2 = 24;
		std::cout << C_CYAN << "int1: " << C_RESET << int1 << " " << C_CYAN << "int2: " << C_RESET << int2 << std::endl;
		std::cout << C_MAGENTA << "Returning: " << ::min(int1, int2) << C_RESET << std::endl;
	}
	{
		int int1 = 12;
		int int2 = 52;
		std::cout << C_CYAN << "int1: " << C_RESET << int1 << " " << C_CYAN << "int2: " << C_RESET << int2 << std::endl;
		std::cout << C_MAGENTA << "Returning: " << ::min(int1, int2) << C_RESET << std::endl;
	}
		{
		int int1 = 12;
		int int2 = 12;
		std::cout << C_CYAN << "int1 (" << &int1 << "): " << C_RESET << int1 << " " << C_CYAN << "int2 (" << &int2 << "): " << C_RESET << int2 << std::endl;
		std::cout << C_MAGENTA << "Returning address: " << &::min(int1, int2) << C_RESET << std::endl;
	}
	std::cout << C_YELLOW << "ENDING MINTESTS()" << C_RESET << std::endl << std::endl;
}

static void maxTests() {
	std::cout << C_YELLOW << "RUNNING MAXTESTS() FOR STRINGS" << C_RESET << std::endl;
	{

		std::string str1("hello");
		std::string str2("world");
		std::cout << C_CYAN << "str1: " << C_RESET << str1 << " " << C_CYAN << "str2: " << C_RESET << str2 << std::endl;
		std::cout << C_MAGENTA << "Returning: " << ::max(str1, str2) << C_RESET << std::endl;
	}
	std::cout << C_YELLOW << "RUNNING MAXTESTS() FOR INTEGERS" << C_RESET << std::endl;
	{

		int int1 = 42;
		int int2 = 24;
		std::cout << C_CYAN << "int1: " << C_RESET << int1 << " " << C_CYAN << "int2: " << C_RESET << int2 << std::endl;
		std::cout << C_MAGENTA << "Returning: " << ::max(int1, int2) << C_RESET << std::endl;
	}
	{
		int int1 = 12;
		int int2 = 52;
		std::cout << C_CYAN << "int1: " << C_RESET << int1 << " " << C_CYAN << "int2: " << C_RESET << int2 << std::endl;
		std::cout << C_MAGENTA << "Returning: " << ::max(int1, int2) << C_RESET << std::endl;
	}
	{
		int int1 = 12;
		int int2 = 12;
		std::cout << C_CYAN << "int1 (" << &int1 << "): " << C_RESET << int1 << " " << C_CYAN << "int2 (" << &int2 << "): " << C_RESET << int2 << std::endl;
		std::cout << C_MAGENTA << "Returning address: " << &::max(int1, int2) << C_RESET << std::endl;
	}
	std::cout << C_YELLOW << "ENDING MAXTESTS()" << C_RESET << std::endl << std::endl;
}

static void mandatoryTests() {
	std::cout << C_YELLOW << "RUNNING MANDATORYTESTS() FOR INTEGERS" << C_RESET << std::endl;
	{
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	std::cout << C_YELLOW << "ENDING MANDATORYTESTS()" << C_RESET << std::endl << std::endl;
}

static int runTests() {
	swapTests();
	minTests();
	maxTests();
	mandatoryTests();
	return 0;
}

int main() {
	runTests();
}