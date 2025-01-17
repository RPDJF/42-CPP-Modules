#include "./AForm.hpp"

std::ostream& AForm::annonce() const {
	return std::cout << C_MAGENTA << "AForm " << C_YELLOW << "(" << this->name_ << ") " << C_RESET;
}

AForm::AForm(): name_("selling"), reqSignGrade_(Bureaucrat::MIN_GRADE), reqExecGrade_(Bureaucrat::MIN_GRADE), isSigned_(false) {
	this->annonce() << "has been created!" << std::endl;
}

AForm::AForm(const std::string& name, int reqSignGrade, int reqExecGrade): name_(name), reqSignGrade_(reqSignGrade), reqExecGrade_(reqExecGrade), isSigned_(false) {
	if (reqSignGrade < Bureaucrat::MAX_GRADE || reqExecGrade < Bureaucrat::MAX_GRADE)
		throw GradeTooHighException();
	else if (reqSignGrade > Bureaucrat::MIN_GRADE || reqExecGrade > Bureaucrat::MIN_GRADE)
		throw GradeTooLowException();
	this->annonce() << "has been created!" << std::endl;
}

AForm::AForm(const AForm& copy): name_(copy.name_), reqSignGrade_(copy.reqSignGrade_), reqExecGrade_(copy.reqExecGrade_), isSigned_(copy.isSigned_) {
	if (this->reqSignGrade_ < Bureaucrat::MAX_GRADE || this->reqExecGrade_ < Bureaucrat::MAX_GRADE)
		throw GradeTooHighException();
	else if (this->reqSignGrade_ > Bureaucrat::MIN_GRADE || this->reqExecGrade_ > Bureaucrat::MAX_GRADE)
		throw GradeTooLowException();
	this->annonce() << "has been created!" << std::endl;
}

AForm::~AForm() {
	this->annonce() << C_RED << "has been destroyed!" << C_RESET << std::endl;
}

AForm& AForm::operator=(const AForm& assign) {
	if (this == &assign)
		return *this;
	this->isSigned_ = assign.isSigned_;
	this->annonce() << "has same signature as " << C_YELLOW << assign.name_ << C_RESET << std::endl;
	return *this;
}

const std::string& AForm::getName() const { return this->name_; }
int AForm::getReqSignGrade() const { return this->reqSignGrade_; }
int AForm::getReqExecGrade() const { return this->reqExecGrade_; }
bool AForm::isSigned() const { return this->isSigned_; }

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat < this->reqSignGrade_)
		throw GradeTooLowException();
	else if (this->isSigned_)
		throw FormAlreadySignedException();
	this->isSigned_ = true;
}

void AForm::execute(const Bureaucrat& executor) {
	if (executor < this->reqExecGrade_)
		throw GradeTooLowException();
	else if (!this->isSigned_)
		throw FormNotSignedException();
}

std::ostream& operator<<(std::ostream& stream, const AForm& form) {
	return stream << form.getName() << " form:" << std::endl
		<< "\tis signed: " << form.isSigned() << std::endl
		<< "\trequested grade to sign: " << form.getReqSignGrade() << std::endl
		<< "\trequested grade to execute: " << form.getReqExecGrade() << std::endl;
}

const char * AForm::GradeTooLowException::what() const throw() { return "grade is too low!"; }
const char * AForm::GradeTooHighException::what() const throw() { return "grade is too high!"; }
const char * AForm::FormNotSignedException::what() const throw() { return "form not signed!"; }
const char * AForm::FormAlreadySignedException::what() const throw() { return "form is already signed!"; }