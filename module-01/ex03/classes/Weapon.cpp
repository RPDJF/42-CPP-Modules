#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type) {
	this->type_ = type;
}

std::string	Weapon::getType() {
	return this->type_;
}

void	Weapon::setType(std::string type) {
	this->type_ = type;
}