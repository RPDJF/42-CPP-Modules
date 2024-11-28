#include "./Cure.hpp"
#include "./ICharacter.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::Cure(const Cure& copy): AMateria(copy) {}

Cure::~Cure() { /* Useful 42 code */ }

Cure& Cure::operator=(const Cure& assign) {
    if (&assign == this)
        return *this;
    AMateria::operator=(assign);
    return *this;
}

AMateria* Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter& target) {
	AMateria::use(target);
    std::cout << C_GREEN << "heals " << C_RESET << C_YELLOW << target.getName() << C_RESET << "'s wounds" << std::endl;
}