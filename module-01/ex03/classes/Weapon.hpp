#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
	private:
		std::string	type_;
	public:
		Weapon();
		Weapon(std::string type);
		std::string	getType();
		void		setType(std::string type);
};

#endif