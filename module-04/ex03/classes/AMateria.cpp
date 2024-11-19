#include "./AMateria.hpp"
#include "./ICharacter.hpp"

#include <cstdio>
AMateria::AMateria(const std::string& type):type_(type) { /* Useful 42 code*/ }

AMateria::AMateria(const AMateria& copy):type_(copy.type_) {}

AMateria::~AMateria() { /* Useful 42 code */ }

AMateria& AMateria::operator=(const AMateria& assign) {
    (void)assign;
    return *this;
}

const std::string& AMateria::getType() const { return (this->type_); }

void AMateria::use(ICharacter& target) {
    std::cout << " ";
    (void)target;
}
