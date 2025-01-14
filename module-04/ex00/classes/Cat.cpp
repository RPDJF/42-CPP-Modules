#include "./Cat.hpp"

static void annonce() {
    std::cout << C_CYAN << "(Cat) " << C_RESET;
}

Cat::Cat(): Animal("Cat") {
    annonce();
    std::cout << "Default constructor call" << std::endl;
}

Cat::Cat(const Cat& copy): Animal(copy) {
    annonce();
    std::cout << "Copy constructor call" << std::endl;
}

Cat::~Cat() {
    annonce();
    std::cout << "Deconstructor call" << std::endl;
}

Cat& Cat::operator=(const Cat& assign) {
	annonce();
	std::cout << "Operator = call" << std::endl;
    if (this == &assign)
        return *this;
    Animal::operator=(assign);
    return *this;
}

void Cat::makeSound() const {
	annonce();
    std::cout << "Meow!" << std::endl;
}