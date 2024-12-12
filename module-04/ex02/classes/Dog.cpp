#include "./Dog.hpp"

static void annonce() {
    std::cout << C_GREEN << "(Dog) " << C_RESET;
}

Dog::Dog(): Animal("Dog"), brain_(new Brain()) {
    annonce();
    std::cout << "Default constructor call" << std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy), brain_(new Brain(*copy.brain_)) {
    annonce();
    std::cout << "Copy constructor call" << std::endl;
}

Dog::~Dog() {
    annonce();
    std::cout << "Deconstructor call" << std::endl;
    delete this->brain_;
}

Dog& Dog::operator=(const Dog& assign) {
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

void Dog::makeSound() const {
    std::cout << "Waf!" << std::endl;
}

Brain *Dog::getBrain() const {
	return this->brain_;
}
