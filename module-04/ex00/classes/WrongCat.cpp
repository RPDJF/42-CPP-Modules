#include "./WrongCat.hpp"

static void annonce() {
    std::cout << C_CYAN << "(WrongCat) " << C_RESET;
}

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
    annonce();
    std::cout << "Default constructor call" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy) {
    annonce();
    std::cout << "Copy constructor call" << std::endl;
}

WrongCat::~WrongCat() {
    annonce();
    std::cout << "Deconstructor call" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& assign) {
	annonce();
	std::cout << "operator= called" << std::endl;
    if (this == &assign)
        return *this;
    WrongAnimal::operator=(assign);
    return *this;
}

void WrongCat::makeSound() const {
	annonce();
    WrongAnimal::makeSound();
}