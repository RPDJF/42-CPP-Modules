#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->name_ = name;
}

Zombie::~Zombie() {
	std::cout << this->name_ << ":  Mh sir, since I didn't found any food, I guess i'm going to die." << std::endl;
}

void	Zombie::announce() {
	std::cout << this->name_ << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}