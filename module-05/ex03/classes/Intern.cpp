#include "./Intern.hpp"

std::ostream& Intern::annonce() const {
	return std::cout << C_CYAN << "Intern " << C_RESET;
}

static AForm *formRobotomyFactory(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm *formShrubberyFactory(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

static AForm *formPresidentialPardonFactory(const std::string& target) {
	return new PresidentialPardonForm(target);
}

t_formula Intern::formulas[Intern::NB_FORMS] = {
  	{"robotomy request", &formRobotomyFactory},
	{"presidential pardon", &formPresidentialPardonFactory},
	{"shrubbery creation", &formShrubberyFactory}
};

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

AForm  *Intern::makeForm(const std::string& type, const std::string& target) const {
	for(int i = 0; i < Intern::NB_FORMS; i++) {
		if (type == Intern::formulas[i].type) {
			this->annonce() << "made " << C_YELLOW << type << C_RESET " form" << std::endl;
			return Intern::formulas[i].makeForm(target);
		}
	}
	this->annonce() << "couldn't make " << type << " form, " << C_RED << "it doesn't exists!!" << C_RESET << std::endl;
	return 0;
}