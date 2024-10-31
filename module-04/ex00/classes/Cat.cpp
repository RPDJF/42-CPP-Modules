#include "./Cat.hpp"

Cat::Cat(): Animal("Cat") {}

Cat::Cat(const Cat& copy): Animal(copy) {}

Cat::~Cat() {/* As useful as a real cat */}

Cat& Cat::operator=(const Cat& assign) {
	if (this == &assign)
		return *this;
	Animal::operator=(assign);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}