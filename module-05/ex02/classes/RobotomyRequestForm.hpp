#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "./AForm.hpp"
# include <fstream>
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm: public AForm {
	private:
		std::ostream& annonce() const;
		static const int REQ_SIGN_GRADE_ = 72;
		static const int REQ_EXEC_GRADE_ = 45;
		const std::string target_;
		static bool isRandomised_;
		// exceptions
		class ShrubberyFileNotCreated: public std::exception { virtual const char *what() const throw(); };
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& name);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& assign);
		void execute(const Bureaucrat& executor);
};

#endif