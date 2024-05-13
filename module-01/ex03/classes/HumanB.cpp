#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name_ = name;
	this->weapon_ = NULL;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon_ = &weapon;
}

void	HumanB::attack() {
	std::cout
		<< this->name_ << " attakcs with their " << this->weapon_->getType()
		<< std::endl;
}