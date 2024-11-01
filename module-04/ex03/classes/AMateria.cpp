#include "./AMateria.hpp"

AMateria::AMateria(const std::string& type) {
    this->type = type;
}

AMateria::AMateria(const AMateria& copy) {
    this->type = copy.type;
}

AMateria::~AMateria() { /* Useful 42 code */ }

AMateria& AMateria::operator=(const AMateria& assign) {
    if (&assign == this)
        return *this;
    this->type = assign.type;
    return *this;
}

void AMateria::use(ICharacter& target) {
    std::cout <<
}
