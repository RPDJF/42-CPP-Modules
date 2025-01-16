#include "classes/Bureaucrat.hpp"
#include "utils/colors.h"

void basicTests() {
	std::cout << C_YELLOW << "RUNNING BASICTESTS()" << C_RESET << std::endl;
	{
		const Bureaucrat bureaucrat;
		const Bureaucrat david("David", 1);
		Bureaucrat michel("michel", 100);
		std::cout << michel << std::endl;
		michel = david;
		std::cout << michel << std::endl;
	}
	std::cout << C_YELLOW << "ENDING BASICTESTS()" << C_RESET << std::endl << std::endl;
}

void throwTests() {
	std::cout << C_YELLOW << "RUNNING THROWTESTS()" << C_RESET << std::endl;
	try {
		const Bureaucrat david("David", Bureaucrat::MIN_GRADE + 1);
	} catch(const std::exception& e) {
		std::cout << "throw dected" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	std::cout << C_YELLOW << "ENDING THROWTESTS()" << C_RESET << std::endl << std::endl;
}

int main() {
	basicTests();
	throwTests();
}