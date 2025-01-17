#ifndef INTERN_HPP
# define INTERN_HPP

# include "./Forms.hpp"

typedef struct s_formula {
	std::string type;
	AForm *(*makeForm)(const std::string& target);
} t_formula;

class Intern {
	private:
		static const int NB_FORMS = 3;
		std::ostream& annonce() const;
		static t_formula formulas[NB_FORMS];
	public:
		Intern();
		Intern(const Intern& copy);
		~Intern();
		Intern& operator=(const Intern& assign);
		AForm *makeForm(const std::string& type, const std::string& target) const;
};

#endif