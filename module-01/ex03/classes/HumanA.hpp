#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "HumanB.hpp"
# include "Weapon.hpp"

class HumanA {
	private:
		std::string	name_;
		Weapon		*weapon_;
	public:
		HumanA(std::string name, Weapon &weapon);
		void		attack();
};

#endif