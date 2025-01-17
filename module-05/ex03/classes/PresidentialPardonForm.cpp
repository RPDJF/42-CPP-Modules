#include "./PresidentialPardonForm.hpp"

std::ostream& PresidentialPardonForm::annonce() const {
    return std::cout << C_MAGENTA << "PresidentialPardonForm " << C_YELLOW << "(" << this->getName() << ") " << C_RESET;
}

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardon", REQ_SIGN_GRADE_, REQ_EXEC_GRADE_), target_("target") {
    this->annonce() << "has been created!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardon", REQ_SIGN_GRADE_, REQ_EXEC_GRADE_), target_(target) {
	this->annonce() << "has been created!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form): AForm(form) {
	this->annonce() << "has been created!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    this->annonce() << "has been destroyed!" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& assign) {
    if (this == &assign)
        return *this;
    AForm::operator=(assign);
    this->annonce() << "form as been assigned from " << C_YELLOW << assign.getName() << C_RESET << std::endl;
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) {
    AForm::execute(executor);
	this->annonce() << "*some drilling noises 🕺*" << std::endl;
	std::ostream& stream = this->annonce() << C_GREEN << this->target_ << " " << C_RESET;
	stream << "has been pardoned by Zaphod Beeblebrox. 🕺";
	stream << std::endl;
}

const char * PresidentialPardonForm::ShrubberyFileNotCreated::what() const throw() { return "shrubbery file not created!"; }