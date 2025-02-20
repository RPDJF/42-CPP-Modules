#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "./AForm.hpp"
# include <iostream>
# include "../utils/colors.h"

class AForm;

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
		bool operator<(const Bureaucrat& ref) const;
		bool operator<(int grade) const;
		bool operator>(const Bureaucrat& ref) const;
		bool operator>(int grade) const;
		int getGrade() const;
		void signForm(AForm& form) const;
		void executeForm(AForm& form) const;
		void incrementGrade();
		void decrementGrade();
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);

# endif