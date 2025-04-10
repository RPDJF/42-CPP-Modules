# include "Bureaucrat.hpp"

const int Bureaucrat::MAX_GRADE = 1;
const int Bureaucrat::MIN_GRADE = 150;

std::ostream& Bureaucrat::annonce() const {
	return std::cout << C_GREEN << "Bureaucrat " << C_CYAN << "(" << this->name_ << ") " << C_RESET;
}

Bureaucrat::Bureaucrat(): name_("Didier"), grade_(150) {
	this->annonce() << "just arrived!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name_(name), grade_(grade) {
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->annonce() << "just arrived!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): name_(copy.name_), grade_(copy.grade_) {
	if (this->grade_ < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade_ > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->annonce() << "just arrived!" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& assign) {
	if (this == &assign)
		return *this;
	this->grade_ = assign.grade_;
	this->annonce() << "copied on " << assign.name_ << "'s grade!" << std::endl;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat) {
	return stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
}

Bureaucrat::~Bureaucrat() {
	this->annonce() << C_RED << "found a better place!" << C_RESET << std::endl;
}

bool Bureaucrat::operator<(const Bureaucrat& ref) const { return this->grade_ > ref.grade_; }
bool Bureaucrat::operator<(int grade) const { return this->grade_ > grade; }
bool Bureaucrat::operator>(const Bureaucrat& ref) const { return this->grade_ < ref.grade_; }
bool Bureaucrat::operator>(int grade) const { return this->grade_ < grade; }

const std::string& Bureaucrat::getName() const { return this->name_; }
int Bureaucrat::getGrade() const { return this->grade_; }

void Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSigned(*this);
		this->annonce() << "signed " << C_YELLOW << form.getName() << C_RESET << std::endl;
	} catch(const std::exception& e) {
		this->annonce() << "couldn't sign " << C_YELLOW << form.getName() << C_RESET << " because " << C_RED << e.what() << C_RESET << std::endl;
	}
}

void Bureaucrat::executeForm(AForm& form) const {
	try {
		form.execute(*this);
		this->annonce() << "executed " << C_YELLOW << form.getName() << C_RESET << std::endl;
	} catch(const std::exception& e) {
		this->annonce() << "couldn't execute " << C_YELLOW << form.getName() << C_RESET << " because " << C_RED << e.what() << C_RESET << std::endl;
	}
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return "grade is too low!";
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return "grade is too high!";
}

void Bureaucrat::incrementGrade() {
	if ((this->grade_ - 1) < this->MAX_GRADE) {
		throw Bureaucrat::GradeTooHighException();
	}
	--this->grade_;
}

void Bureaucrat::decrementGrade() {
	if ((this->grade_ + 1) > this->MIN_GRADE) {
		throw Bureaucrat::GradeTooLowException();
	}
	++this->grade_;
}