#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) {
	this->name_ = name;
	this->weapon_ = &weapon;
}

void	HumanA::attack() {
	std::cout
		<< this->name_ << " attakcs with their " << this->weapon_->getType()
		<< std::endl;
}