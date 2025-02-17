#include "utils/colors.h"
#include <iostream>
#include "classes/Span.hpp"

static void basicTests() {
	std::cout << C_YELLOW << "RUNNING BASICTESTS() FOR STRINGS" << C_RESET << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp = Span(100);
		sp.fill(sp.begin(), sp.begin() + 100);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	}
	std::cout << C_YELLOW << "ENDING BASICTESTS()" << C_RESET << std::endl << std::endl;
}

static int runTests() {
	basicTests();
	return 0;
}

int main() {
	std::srand(std::time(0));
	runTests();
	//ScalarConverter::convert(argv[1]);
}