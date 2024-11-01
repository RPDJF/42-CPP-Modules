#include "./Ice.hpp"

Ice::Ice(): AMateria(C_CYAN + std::string("ice") + C_RESET) {}

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
   std::cout << "\"* shoots an ice bolt at " << C_YELLOW << target.getName() << C_RESET << " *\"" << std::endl;
}