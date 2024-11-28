#include "./Thunder.hpp"
#include "./ICharacter.hpp"

Thunder::Thunder(): AMateria("thunder") { /* Useful 42 code*/ }

Thunder::Thunder(const Thunder& copy): AMateria(copy) {}

Thunder::~Thunder() { /* Useful 42 code */ }

Thunder& Thunder::operator=(const Thunder& assign) {
    if (&assign == this)
        return *this;
    AMateria::operator=(assign);
    return *this;
}

AMateria* Thunder::clone() const { return new Thunder(*this); }

void Thunder::use(ICharacter& target) {
    AMateria::use(target);
    std::cout << "shoots an " << C_YELLOW << "thunder bolt" << C_RESET << " at " << C_YELLOW << target.getName() << C_RESET << " " << std::endl;
}