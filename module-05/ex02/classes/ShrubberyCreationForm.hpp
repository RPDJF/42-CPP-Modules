#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "./AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm {
	private:
		std::ostream& annonce() const;
		static const int REQ_SIGN_GRADE_ = 145;
		static const int REQ_EXEC_GRADE_ = 137;
		const std::string target_;
		void createShrubberyFile() const;
		// exceptions
		class ShrubberyFileNotCreated: public std::exception { virtual const char *what() const throw(); };
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& name);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& assign);
		void execute(const Bureaucrat& executor);
};

#endif