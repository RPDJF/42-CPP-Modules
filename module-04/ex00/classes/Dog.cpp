#include "./Dog.hpp"

static void annonce() {
    std::cout << C_GREEN << "(Dog) " << C_RESET;
}

Dog::Dog(): Animal("Dog") {
    annonce();
    std::cout << "Default constructor call" << std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy) {
    annonce();
    std::cout << "Copy constructor call" << std::endl;
}

Dog::~Dog() {
    annonce();
    std::cout << "Deconstructor call" << std::endl;
}

Dog& Dog::operator=(const Dog& assign) {
	annonce();
	std::cout << "Operator = call" << std::endl;
    if (this == &assign)
        return *this;
    Animal::operator=(assign);
    return *this;
}

void Dog::makeSound() const {
	annonce();
    std::cout << "waf!" << std::endl;
}