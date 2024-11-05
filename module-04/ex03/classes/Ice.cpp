#include "./Ice.hpp"
#include "./ICharacter.hpp"

Ice::Ice(): AMateria(C_CYAN + std::string("ice") + C_RESET) {
    std::cout << "Ice default constructor called.\nType:" << this->getType() << std::endl;
}

Ice::Ice(const Ice& copy): AMateria(copy) {}

Ice::~Ice() { /* Useful 42 code */ }

Ice& Ice::operator=(const Ice& assign) {
    if (&assign == this)
        return *this;
    AMateria::operator=(assign);
    return *this;
}

AMateria* Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter& target) {
    AMateria::use(target);
    std::cout << "shoots an " << C_CYAN << "ice bolt" << C_RESET << " at " << C_YELLOW << target.getName() << C_RESET << " " << std::endl;
}