#include "./WrongCat.hpp"

static void annonce() {
    std::cout << C_RED << "(WrongCat) " << C_RESET;
}

WrongCat::WrongCat(): Animal("WrongCat") {
    annonce();
    std::cout << "Default constructor call" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy): Animal(copy) {
    annonce();
    std::cout << "Copy constructor call" << std::endl;
}

WrongCat::~WrongCat() {
    annonce();
    std::cout << "Deconstructor call" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& assign) {
	if (this == &assign)
		return *this;
	Animal::operator=(assign);
	return *this;
}
