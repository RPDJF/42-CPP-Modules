#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "../utils/colors.h"

class Bureaucrat {
	private:
		std::ostream& annonce() const;
		const std::string name_;
		int grade_;
		// exceptions
		class GradeTooLowException: public std::exception { virtual const char *what() const throw(); };
		class GradeTooHighException: public std::exception { virtual const char *what() const throw(); };
	public:
		static const int MIN_GRADE;
		static const int MAX_GRADE;

		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& assign);
		~Bureaucrat();
		const std::string& getName() const;
		int getGrade() const;
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);

# endif