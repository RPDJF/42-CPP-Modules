#include "./Poison.hpp"
#include "./ICharacter.hpp"

Poison::Poison(): AMateria("poison") { /* Useful 42 code*/ }

Poison::Poison(const Poison& copy): AMateria(copy) {}

Poison::~Poison() { /* Useful 42 code */ }

Poison& Poison::operator=(const Poison& assign) {
    if (&assign == this)
        return *this;
    AMateria::operator=(assign);
    return *this;
}

AMateria* Poison::clone() const { return new Poison(*this); }

void Poison::use(ICharacter& target) {
    AMateria::use(target);
    std::cout << "shoots an " << C_MAGENTA << "poison spear" << C_RESET << " at " << C_YELLOW << target.getName() << C_RESET << " " << std::endl;
}