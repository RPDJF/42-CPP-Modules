#include "./Cat.hpp"

static void annonce() {
    std::cout << C_CYAN << "(Cat) " << C_RESET;
}

Cat::Cat(): Animal("Cat"), brain_(new Brain()) {
    annonce();
    std::cout << "Default constructor call" << std::endl;
}

Cat::Cat(const Cat& copy): Animal(copy), brain_(new Brain(*copy.brain_)) {
    annonce();
    std::cout << "Copy constructor call" << std::endl;
}

Cat::~Cat() {
    annonce();
    std::cout << "Deconstructor call" << std::endl;
    delete this->brain_;
}

Cat& Cat::operator=(const Cat& assign) {
	annonce();
	std::cout << "operator= called" << std::endl;
    if (this == &assign) {
        return *this;
	}
    Animal::operator=(assign);
	delete this->brain_;
	this->brain_ = new Brain(*assign.brain_);
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

Brain *Cat::getBrain() const {
	return this->brain_;
}
