#include "./Intern.hpp"

std::ostream& Intern::annonce() const {
	return std::cout << C_CYAN << "Intern " << C_RESET;
}

void Intern::init() {
	this->formulas[0].type = "robotomy request";
	this->formulas[0].makeForm = &RobotomyRequestForm();
}

Intern::Intern() {
	this->annonce() << "has been hired!" << std::endl;
}

Intern::Intern(const Intern& copy) {
	(void)copy;
	this->annonce() << "has been hired!" << std::endl;
}

Intern::~Intern() {
	this->annonce() << C_RED << "has been fired!!" << C_RESET << std::endl;
}

Intern& Intern::operator=(const Intern& assign) {
	if (this == &assign)
		return *this;
	return *this;
}

AForm  Intern::*makeForm(const std::string& name, const std::string& formType) {
	
}