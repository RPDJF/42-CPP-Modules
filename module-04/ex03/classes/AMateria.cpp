#include "./AMateria.hpp"
#include "./ICharacter.hpp"

#include <cstdio>
AMateria::AMateria(const std::string& type):type_(type) {
    std::cout << "AMateria default constructor called.\nType:" << this->getType() << std::endl;
}

AMateria::AMateria(const AMateria& copy):type_(copy.type_) {}

AMateria::~AMateria() { /* Useful 42 code */ }

AMateria& AMateria::operator=(const AMateria& assign) {
    if (&assign == this)
        return *this;
    *this = assign;
    return *this;
}

const std::string& AMateria::getType() const { return (this->type_); }

void AMateria::use(ICharacter& target) {
    std::cout << " ";
    (void)target;
}
