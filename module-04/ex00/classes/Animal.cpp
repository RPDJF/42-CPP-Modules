#include "./Animal.hpp"

Animal::Animal() : type_("") {}

Animal::Animal(const std::string& type) : type_(type) {}

Animal::Animal(const Animal& copy) : type_(copy.type_) {}

Animal::~Animal() {/* Useful code, don't mind about me */}

Animal& Animal::operator=(const Animal& assign) {
	if (this == &assign)
		return *this;
	this->type_ = assign.type_;
	return *this;
}

const std::string& Animal::getType() const { return (this->type_); }

void Animal::makeSound() const {
	std::cout << "Hey. I'm Bob." << std::endl;
}