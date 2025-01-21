#include "classes/ScalarConverter.hpp"
#include "utils/colors.h"
#include "utils/MyStd.hpp"
#include <cfloat>

static void basicTests() {
	std::cout << C_YELLOW << "RUNNING BASICTESTS()" << C_RESET << std::endl;
	{
		std::string tests[] = {"42", "42.2", "42.2f", "42.2d", "+42", "-42", "++42", "--42", "nan", "2147483647", "2147483648", MyStd::to_string(FLT_MAX * 1.1), ""};
		std::string *test;
		int i = 0;
		do {
			test = &tests[i];
			std::cout << C_CYAN << "testing " << *test << C_RESET << std::endl;
			ScalarConverter::convert(*test);
			i++;
		} while (!tests[i].empty());
	}
	std::cout << C_YELLOW << "ENDING BASICTESTS()" << C_RESET << std::endl << std::endl;
}

static int runTests() {
	basicTests();
	return 0;
}

static int tooManyArgs() {
	std::cout << C_RED << "Error: Too many arguments" << C_RESET << std::endl;
	return 1;
}

int main(int argc, char **argv) {
	if (argc == 1) return (runTests());
	else if (argc > 2) return (tooManyArgs());
	
	ScalarConverter::convert(argv[1]);
}