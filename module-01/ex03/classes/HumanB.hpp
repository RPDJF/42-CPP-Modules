#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "HumanA.hpp"
# include "Weapon.hpp"

class HumanB {
	private:
		std::string	name_;
		Weapon		*weapon_;
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon &weapon);
		void	attack();
};

#endif