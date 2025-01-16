#ifndef FORM_HPP
# define FORM_HPP

# include "./Bureaucrat.hpp"
# include <ostream>

class Bureaucrat;

class Form {
	private:
		std::ostream& annonce() const;
		const std::string name_;
		const int reqSignGrade_;
		const int reqExecGrade_;
		bool isSigned_;
		// exceptions
		class GradeTooLowException: public std::exception { virtual const char *what() const throw(); };
		class GradeTooHighException: public std::exception { virtual const char *what() const throw(); };
	public:
		Form();
		Form(const std::string& name, int reqSignGrade, int reqExecGrade);
		Form(const Form& copy);
		~Form();
		Form& operator=(const Form& assign);
		const std::string& getName() const;
		int getReqSignGrade() const;
		int getReqExecGrade() const;
		bool isSigned() const;
		void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& stream, const Form& form);

#endif