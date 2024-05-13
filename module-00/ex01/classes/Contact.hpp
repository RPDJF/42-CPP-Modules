#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include "../utils/readline.hpp"

class Contact {
	public:
		void	init();
		bool		is_empty();
		std::string getFirstname();
		std::string getLastname();
		std::string getNickname();
		std::string getPhoneNumber();
		void	printContact();
	private:
		bool		is_empty_;
		std::string	firstname_;
		std::string lastname_;
		std::string nickname_;
		std::string phone_number_;
		std::string darkest_secret_;
};

#endif