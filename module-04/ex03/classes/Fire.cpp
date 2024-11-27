#include "./Fire.hpp"
#include "./ICharacter.hpp"

Fire::Fire(): AMateria(C_RED + std::string("fire") + C_RESET) { /* Useful 42 code*/ }

Fire::Fire(const Fire& copy): AMateria(copy) {}

Fire::~Fire() { /* Useful 42 code */ }

Fire& Fire::operator=(const Fire& assign) {
    if (&assign == this)
        return *this;
    AMateria::operator=(assign);
    return *this;
}

AMateria* Fire::clone() const { return new Fire(*this); }

void Fire::use(ICharacter& target) {
    AMateria::use(target);
    std::cout << "shoots an " << C_RED << "fire bolt" << C_RESET << " at " << C_YELLOW << target.getName() << C_RESET << " " << std::endl;
}