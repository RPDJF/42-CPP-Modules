#include "Zombie.hpp"
Zombie::Zombie() {
}

Zombie::Zombie(std::string name) {
	this->name_ = name;
}

Zombie::~Zombie() {
	std::cout << this->name_ << ":  Mh sir, since I didn't found any food, I guess I'm going to die." << std::endl;
}

void	Zombie::setName(std::string name) {
	this->name_ = name;
}

void	Zombie::annonce() {
	std::cout << this->name_ << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}