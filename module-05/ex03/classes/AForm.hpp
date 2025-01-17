#ifndef AFORM_HPP
# define AFORM_HPP

# include "./Bureaucrat.hpp"
# include <ostream>

class Bureaucrat;

class AForm {
	private:
		std::ostream& annonce() const;
		const std::string name_;
		const int reqSignGrade_;
		const int reqExecGrade_;
		bool isSigned_;
		// exceptions
		class GradeTooLowException: public std::exception { virtual const char *what() const throw(); };
		class GradeTooHighException: public std::exception { virtual const char *what() const throw(); };
		class FormAlreadySignedException: public std::exception { virtual const char *what() const throw(); };
		class FormNotSignedException: public std::exception { virtual const char *what() const throw(); };
	public:
		AForm();
		AForm(const std::string& name, int reqSignGrade, int reqExecGrade);
		AForm(const AForm& copy);
		virtual ~AForm() = 0;
		AForm& operator=(const AForm& assign);
		const std::string& getName() const;
		int getReqSignGrade() const;
		int getReqExecGrade() const;
		bool isSigned() const;
		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(const Bureaucrat& executor);
};

std::ostream& operator<<(std::ostream& stream, const AForm& form);

#endif