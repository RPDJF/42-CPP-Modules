#include "./Form.hpp"

std::ostream& Form::annonce() const {
	return std::cout << C_MAGENTA << "Form " << C_YELLOW << "(" << this->name_ << ") " << C_RESET;
}

Form::Form(): name_("selling"), reqSignGrade_(Bureaucrat::MIN_GRADE), reqExecGrade_(Bureaucrat::MIN_GRADE), isSigned_(false) {
	this->annonce() << "has been created!" << std::endl;
}

Form::Form(const std::string& name, int reqSignGrade, int reqExecGrade): name_(name), reqSignGrade_(reqSignGrade), reqExecGrade_(reqExecGrade), isSigned_(false) {
	if (reqSignGrade < Bureaucrat::MAX_GRADE || reqExecGrade < Bureaucrat::MAX_GRADE)
		throw GradeTooHighException();
	else if (reqSignGrade > Bureaucrat::MIN_GRADE || reqExecGrade > Bureaucrat::MIN_GRADE)
		throw GradeTooLowException();
	this->annonce() << "has been created!" << std::endl;
}

Form::Form(const Form& copy): name_(copy.name_), reqSignGrade_(copy.reqSignGrade_), reqExecGrade_(copy.reqExecGrade_), isSigned_(copy.isSigned_) {
	if (this->reqSignGrade_ < Bureaucrat::MAX_GRADE || this->reqExecGrade_ < Bureaucrat::MAX_GRADE)
		throw GradeTooHighException();
	else if (this->reqSignGrade_ > Bureaucrat::MIN_GRADE || this->reqExecGrade_ > Bureaucrat::MAX_GRADE)
		throw GradeTooLowException();
	this->annonce() << "has been created!" << std::endl;
}

Form::~Form() {
	this->annonce() << C_RED << "has been destroyed!" << C_RESET << std::endl;
}

Form& Form::operator=(const Form& assign) {
	if (this == &assign)
		return *this;
	this->isSigned_ = assign.isSigned_;
	this->annonce() << "has same signature as " << C_YELLOW << assign.name_ << C_RESET << std::endl;
	return *this;
}

const std::string& Form::getName() const { return this->name_; }
int Form::getReqSignGrade() const { return this->reqSignGrade_; }
int Form::getReqExecGrade() const { return this->reqExecGrade_; }
bool Form::isSigned() const { return this->isSigned_; }

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat < this->reqSignGrade_)
		throw GradeTooLowException();
	this->isSigned_ = true;
}

std::ostream& operator<<(std::ostream& stream, const Form& form) {
	return stream << form.getName() << " form:" << std::endl
		<< "\tis signed: " << form.isSigned() << std::endl
		<< "\trequested grade to sign: " << form.getReqSignGrade() << std::endl
		<< "\trequested grade to execute: " << form.getReqExecGrade() << std::endl;
}

const char * Form::GradeTooLowException::what() const throw() {
	return "grade is too low!";
}

const char * Form::GradeTooHighException::what() const throw() {
	return "grade is too high!";
}