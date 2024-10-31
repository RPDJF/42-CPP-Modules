#include "./WrongCat.hpp"

WrongCat::WrongCat(): Animal("WrongCat") {}

WrongCat::WrongCat(const WrongCat& copy): Animal(copy) {}

WrongCat::~WrongCat() {/* As useful as a real WrongCat */}

WrongCat& WrongCat::operator=(const WrongCat& assign) {
	if (this == &assign)
		return *this;
	Animal::operator=(assign);
	return *this;
}
