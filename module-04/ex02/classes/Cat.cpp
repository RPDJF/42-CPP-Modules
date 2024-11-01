#include "./Cat.hpp"

static void annonce() {
    std::cout << C_CYAN << "(Cat) " << C_RESET;
}

Cat::Cat(): Animal("Cat") {
    annonce();
    std::cout << "Default constructor call" << std::endl;
    this->brain_ = new Brain();
}

Cat::Cat(const Cat& copy): Animal(copy) {
    annonce();
    std::cout << "Copy constructor call" << std::endl;
}

Cat::~Cat() {
    annonce();
    std::cout << "Deconstructor call" << std::endl;
    delete this->brain_;
}

Cat& Cat::operator=(const Cat& assign) {
    if (this == &assign)
        return *this;
    Animal::operator=(assign);
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}