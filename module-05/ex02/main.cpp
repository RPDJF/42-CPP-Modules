#include "classes/Bureaucrat.hpp"
#include "classes/ShrubberyCreationForm.hpp"
#include "classes/RobotomyRequestForm.hpp"
#include "classes/PresidentialPardonForm.hpp"
#include "utils/colors.h"

void basicTests() {
	std::cout << C_YELLOW << "RUNNING BASICTESTS()" << C_RESET << std::endl;
	{
		const ShrubberyCreationForm shrubberyCreationForm;
		const ShrubberyCreationForm marriage("marriage");
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
		const Bureaucrat david("David", Bureaucrat::MAX_GRADE);
		const Bureaucrat michel("Michel", Bureaucrat::MIN_GRADE);
		ShrubberyCreationForm marriage = ShrubberyCreationForm("Marriage");
		std::cout << david << std::endl << michel << std::endl << marriage;
		michel.signForm(marriage);
		std::cout << "is " << C_YELLOW << marriage.getName() << C_RESET << " signed: " << (marriage.isSigned()? (std::string(C_GREEN) + "true") : (std::string(C_RED) + "false")) << std::endl;
		david.signForm(marriage);
		std::cout << "is " << C_YELLOW << marriage.getName() << C_RESET << " signed: " << (marriage.isSigned()? (std::string(C_GREEN) + "true") : (std::string(C_RED) + "false")) << std::endl;
		david.signForm(marriage);
	}
	std::cout << C_YELLOW << "ENDING SIGNTESTS()" << C_RESET << std::endl << std::endl;
}

void executeTests() {
	std::cout << C_YELLOW << "RUNNING EXECUTETESTS()" << C_RESET << std::endl;
	{
		ShrubberyCreationForm michelsh("michelsh");
		ShrubberyCreationForm davidsh("davidsh");
		RobotomyRequestForm michelrb("michelrb");
		PresidentialPardonForm michelpp("michelpp");
		Bureaucrat michel("Michel", Bureaucrat::MAX_GRADE);
		Bureaucrat david("David", Bureaucrat::MIN_GRADE);
		michel.signForm(michelsh);
		michel.signForm(davidsh);
		michel.executeForm(michelsh);
		david.executeForm(davidsh);
		michel.signForm(michelrb);
		michel.executeForm(michelrb);
		michel.signForm(michelpp);
		michel.executeForm(michelpp);
	}
	std::cout << C_YELLOW << "ENDING EXECUTETESTS()" << C_RESET << std::endl << std::endl;
}

void throwTests() {
	std::cout << C_YELLOW << "RUNNING THROWTESTS()" << C_RESET << std::endl;
	try {
		const Bureaucrat david("David", Bureaucrat::MIN_GRADE + 1);
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
	executeTests();
}