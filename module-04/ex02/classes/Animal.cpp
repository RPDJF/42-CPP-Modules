#include "./Animal.hpp"

static void annonce() {
    std::cout << C_YELLOW << "(Animal) " << C_RESET;
}

Animal::Animal() : type_("") {
    annonce();
    std::cout << "Default constructor call" << std::endl;
}

Animal::Animal(const std::string& type) : type_(type) {
    annonce();
    std::cout << "Type constructor call " << C_MAGENTA << type <<  C_RESET << std::endl;
}

Animal::Animal(const Animal& copy) : type_(copy.type_) {
    annonce();
    std::cout << "Copy constructor call" << std::endl;
}

Animal::~Animal() {
    annonce();
    std::cout << "Deconstructor call " << C_MAGENTA << this->type_ << C_RESET << std::endl;
}

Animal& Animal::operator=(const Animal& assign) {
    if (this == &assign)
        return *this;
    this->type_ = assign.type_;
    return *this;
}

const std::string& Animal::getType() const { return (this->type_); }

void Animal::makeSound() const {
    std::cout << "Hey. I'm Bob." << std::endl;
}