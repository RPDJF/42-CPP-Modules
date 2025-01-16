#include "classes/Bureaucrat.hpp"
#include "utils/colors.h"

void basicTests() {
	std::cout << C_YELLOW << "RUNNING BASICTESTS()" << C_RESET << std::endl;
	{
		const Form form;
		const Form marriage("marriage", Bureaucrat::MIN_GRADE, Bureaucrat::MIN_GRADE);
		const Bureaucrat bureaucrat;
		const Bureaucrat david("David", 1);
		Bureaucrat michel("michel", 100);
		std::cout << michel << std::endl;
		michel = david;
		std::cout << michel << std::endl;

	}
	std::cout << C_YELLOW << "ENDING BASICTESTS()" << C_RESET << std::endl << std::endl;
}

void signTests() {
	std::cout << C_YELLOW << "RUNNING SIGNTESTS()" << C_RESET << std::endl;
	{
		const Bureaucrat david("David", 100);
		const Bureaucrat michel("Michel", 120);
		Form marriage("Marriage", 110, 110);
		std::cout << david << std::endl << michel << std::endl << marriage;
		michel.signForm(marriage);
		std::cout << "is " << C_YELLOW << marriage.getName() << C_RESET << " signed: " << (marriage.isSigned()? (std::string(C_GREEN) + "true") : (std::string(C_RED) + "false")) << std::endl;
		david.signForm(marriage);
		std::cout << "is " << C_YELLOW << marriage.getName() << C_RESET << " signed: " << (marriage.isSigned()? (std::string(C_GREEN) + "true") : (std::string(C_RED) + "false")) << std::endl;
		david.signForm(marriage);
	}
	std::cout << C_YELLOW << "ENDING SIGNTESTS()" << C_RESET << std::endl << std::endl;
}

void throwTests() {
	std::cout << C_YELLOW << "RUNNING THROWTESTS()" << C_RESET << std::endl;
	try {
		const Bureaucrat david("David", Bureaucrat::MIN_GRADE + 1);
	} catch(const std::exception& e) {
		std::cout << "throw detected" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	try {
		const Form marriage("Marriage", Bureaucrat::MIN_GRADE + 1, Bureaucrat::MIN_GRADE + 1);
	} catch(const std::exception& e) {
		std::cout << "throw detected" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	std::cout << C_YELLOW << "ENDING THROWTESTS()" << C_RESET << std::endl << std::endl;
}

int main() {
	basicTests();
	throwTests();
	signTests();
}