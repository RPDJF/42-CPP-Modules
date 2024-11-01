#include "./Cure.hpp"

Cure::Cure(): AMateria(C_GREEN + std::string("cure") + C_RESET) {}

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
    std::cout << "\"* heals " << C_YELLOW << target.getName() << C_RESET << "'s wounds *\"" << std::endl;
}