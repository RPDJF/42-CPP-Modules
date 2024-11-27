#include "./AMateria.hpp"
#include "./ICharacter.hpp"

#include <cstdio>
AMateria::AMateria(const std::string& type):type_(type), isEquiped_(false) {
	std::cout << "A new " << this->type_ << " materia appeared on the battlefield ! (" << C_YELLOW << "n°" << this << C_RESET << ")" << std::endl;
}

AMateria::AMateria(const AMateria& copy):type_(copy.type_), isEquiped_(false) {}

AMateria::~AMateria() { /* Useful 42 code */ }

AMateria& AMateria::operator=(const AMateria& assign) {
    (void)assign;
    return *this;
}

const std::string& AMateria::getType() const { return (this->type_); }

bool AMateria::isEquiped() const { return (this->isEquiped_); }

void AMateria::setEquip(bool status) { this->isEquiped_ = status; }

void AMateria::use(ICharacter& target) {
    std::cout << " ";
    (void)target;
}
