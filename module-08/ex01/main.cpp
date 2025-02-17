#include "utils/colors.h"
#include <iostream>
#include "classes/Span.hpp"

static void basicTests() {
	std::cout << C_YELLOW << "RUNNING BASICTESTS()" << C_RESET << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << " (Expected: 2)" << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << " (Expected: 14)" << std::endl;

		std::cout << std::endl;

		// Overwrite sp with new tricky values
		sp = Span(5);
		sp.addNumber(INT_MAX);
		sp.addNumber(INT_MIN);
		sp.addNumber(0);
		sp.addNumber(-1);
		sp.addNumber(1);
		std::cout << "Shortest span with tricky values: " << sp.shortestSpan() << " (Expected: 1)" << std::endl;
		std::cout << "Longest span with tricky values: " << sp.longestSpan() << " (Expected: " << static_cast<unsigned int>(INT_MAX) - static_cast<unsigned int>(INT_MIN) << ")" << std::endl;

		std::cout << std::endl;

		// Overwrite sp with more tricky values
		sp = Span(5);
		sp.addNumber(100);
		sp.addNumber(101);
		sp.addNumber(102);
		sp.addNumber(103);
		sp.addNumber(104);
		std::cout << "Shortest span with close values: " << sp.shortestSpan() << " (Expected: 1)" << std::endl;
		std::cout << "Longest span with close values: " << sp.longestSpan() << " (Expected: 4)" << std::endl;

		std::cout << std::endl;

		// Overwrite sp with duplicate values
		sp = Span(5);
		sp.addNumber(42);
		sp.addNumber(42);
		sp.addNumber(42);
		sp.addNumber(42);
		sp.addNumber(42);
		std::cout << "Shortest span with duplicate values: " << sp.shortestSpan() << " (Expected: 0)" << std::endl;
		std::cout << "Longest span with duplicate values: " << sp.longestSpan() << " (Expected: 0)" << std::endl;

		std::cout << std::endl;

		// Seed the random number generator
		std::srand(std::time(0));

		// Create a new Span object with a larger size
		sp = Span(10);
		sp.fill(sp.begin(), sp.begin() + 10);
		std::cout << "Shortest span with random values: " << sp.shortestSpan() << " (Expected: varies)" << std::endl;
		std::cout << "Longest span with random values: " << sp.longestSpan() << " (Expected: varies)" << std::endl;
	}
	std::cout << C_YELLOW << "ENDING BASICTESTS()" << C_RESET << std::endl << std::endl;
}

static int runTests() {
	basicTests();
	return 0;
}

int main() {
	runTests();
}