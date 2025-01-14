#include "./WrongAnimal.hpp"

static void annonce() {
    std::cout << C_YELLOW << "(WrongAnimal) " << C_RESET;
}

WrongAnimal::WrongAnimal() : type_("elle boit du sprite") {
    annonce();
    std::cout << "Default constructor call" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type_(type) {
    annonce();
    std::cout << "Type constructor call " << C_MAGENTA << type <<  C_RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : type_(copy.type_) {
    annonce();
    std::cout << "Copy constructor call" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    annonce();
    std::cout << "Deconstructor call " << C_MAGENTA << this->type_ << C_RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& assign) {
	annonce();
	std::cout << "operator= called" << std::endl;
    if (this == &assign)
        return *this;
    this->type_ = assign.type_;
    return *this;
}

const std::string& WrongAnimal::getType() const { return (this->type_); }

void WrongAnimal::makeSound() const {
	annonce();
    std::cout << ".boB m'I .yeH" << std::endl;
}