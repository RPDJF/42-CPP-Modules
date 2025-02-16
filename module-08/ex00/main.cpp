#include "utils/colors.h"
#include "./easyfind.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

static void basicTests() {
	std::cout << C_YELLOW << "RUNNING BASICTESTS() FOR STRINGS" << C_RESET << std::endl;
	{
		std::vector<int> container;
		container.reserve(8);
		container.push_back(0);
		container.push_back(4);
		container.push_back(2);
		container.push_back(1);
		container.push_back(8);
		container.push_back(7);
		container.push_back(42);
		container.push_back(2);
		std::cout << C_CYAN << "Searching 42 in {0, 4, 2, 1, 8, 7, 42, 2}" << C_RESET << std::endl;
		std::vector<int>::iterator found = easyfind(container, 42);
		if (found == container.end()) {
			std::cerr << C_RED << "not found 42 in {0, 4, 2, 1, 8, 7, 42, 2}" << std::endl;
		} else {
			std::cout << C_GREEN << "Found " << *found << " in {0, 4, 2, 1, 8, 7, 42, 2}" << C_RESET << std::endl;
		}
		std::cout << C_CYAN << "Searching 43 in {0, 4, 2, 1, 8, 7, 42, 2}" << C_RESET << std::endl;
		found = easyfind(container, 43);
		if (found == container.end()) {
			std::cerr << C_RED << "Not found 43 in {0, 4, 2, 1, 8, 7, 42, 2}" << std::endl;
		} else {
			std::cout << C_GREEN << "Found " << *found << " in {0, 4, 2, 1, 8, 7, 42, 2}" << C_RESET << std::endl;
		}
	}
	std::cout << C_YELLOW << "ENDING BASICTESTS()" << C_RESET << std::endl << std::endl;
}

static int runTests() {
	basicTests();
	return 0;
}

int main() {
	runTests();
	//ScalarConverter::convert(argv[1]);
}