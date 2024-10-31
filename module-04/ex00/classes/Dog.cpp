#include "./Dog.hpp"

Dog::Dog(): Animal("Dog") {}

Dog::Dog(const Dog& copy): Animal(copy) {}

Dog::~Dog() {/* very useful code, don't touch it */}


Dog& Dog::operator=(const Dog& assign) {
	if (this == &assign)
		return *this;
	Animal::operator=(assign);
	return *this;
}

void Dog::makeSound() const {
	std::cout << "waf!" << std::endl;
}