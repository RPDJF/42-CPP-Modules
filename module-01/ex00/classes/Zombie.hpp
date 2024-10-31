#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
	private:
		std::string	name_;
	public:
		Zombie(std::string name);
		~Zombie();
		void	annonce();
};

#endif