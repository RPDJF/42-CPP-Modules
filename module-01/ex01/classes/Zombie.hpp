#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
	private:
		std::string	name_;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	setName(std::string name);
		void	annonce();
};

Zombie*	zombieHorde(int N, std::string name);

#endif