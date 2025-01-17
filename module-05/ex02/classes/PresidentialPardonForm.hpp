#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "./AForm.hpp"

class PresidentialPardonForm: public AForm {
	private:
		std::ostream& annonce() const;
		static const int REQ_SIGN_GRADE_ = 72;
		static const int REQ_EXEC_GRADE_ = 45;
		const std::string target_;
		// exceptions
		class ShrubberyFileNotCreated: public std::exception { virtual const char *what() const throw(); };
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& name);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& assign);
		void execute(const Bureaucrat& executor);
};

#endif