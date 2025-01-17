#include "./RobotomyRequestForm.hpp"

bool RobotomyRequestForm::isRandomised_ = false;

std::ostream& RobotomyRequestForm::annonce() const {
    return std::cout << C_MAGENTA << "RobotomyRequestForm " << C_YELLOW << "(" << this->getName() << ") " << C_RESET;
}

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequest", REQ_SIGN_GRADE_, REQ_EXEC_GRADE_), target_("target") {
	if (!isRandomised_) {
		this->annonce() << "generating rand seed" << std::endl;
		std::srand(std::time(0));
		isRandomised_ = true;
	}
    this->annonce() << "has been created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequest", REQ_SIGN_GRADE_, REQ_EXEC_GRADE_), target_(target) {
    	if (!isRandomised_) {
		this->annonce() << "generating rand seed" << std::endl;
		std::srand(std::time(0));
		isRandomised_ = true;
	}
	this->annonce() << "has been created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form): AForm(form) {
    	if (!isRandomised_) {
		this->annonce() << "generating rand seed" << std::endl;
		std::srand(std::time(0));
		isRandomised_ = true;
	}
	this->annonce() << "has been created!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    this->annonce() << "has been destroyed!" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& assign) {
    if (this == &assign)
        return *this;
    AForm::operator=(assign);
    this->annonce() << "form as been assigned from " << C_YELLOW << assign.getName() << C_RESET << std::endl;
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) {
    AForm::execute(executor);
	this->annonce() << "*some drilling noises 🕺*" << std::endl;
	std::ostream& stream = this->annonce() << C_GREEN << this->target_ << " " << C_RESET;
	if (std::rand() % 2)
		stream << "has successfully become a robot! 🤖";
	else
		stream << "couldn't turn into a robot..! ❌";
	stream << std::endl;
}

const char * RobotomyRequestForm::ShrubberyFileNotCreated::what() const throw() { return "shrubbery file not created!"; }