#include "./Character.hpp"

void Character::annonce() {
    std::cout << C_YELLOW << this->name_ << C_RESET ;
}

Character::Character(): name_("Bob") {}

Character::Character(const std::string& name): name_(name) {}

Character::Character(const Character& copy): name_(copy.name_), inventory_(copy.inventory_) {}

Character::~Character() { /* Very useful code, don't touch it */}

Character& Character::operator=(const Character& assign) {
    if (this == &assign)
        return *this;
    this->name_ = assign.name_;
    this->inventory_ = assign.inventory_;
    return *this;
}

const std::string& Character::getName() const {
    return this->name_;
}

void Character::equip(AMateria* m) {
    this->annonce();
    if (this->inventory_.getSize() >= 4) {
        std::cout << "'s inventory is already " << C_RED << "full of materia" << C_RESET << "\n"
        << C_YELLOW << "Unequip" << C_RESET << "some materia and try again." << std::endl;
        return;
    }
    this->inventory_.addItem(m);
    std::cout << " equiped " << m->getType() << " materia at position " << this->inventory_.getSize() - 1 << std::endl;
}

void Character::unequip(int idx) {
    AMateria *mat;
    std::string matName;

    this->annonce();
    if (this->inventory_.getSize() >= static_cast<unsigned int>(idx)) {
        std::cout << C_RED << " you can't unequip an item you don't have !" << C_RESET << std::endl;
        return;
    }
    mat = this->inventory_.itemAt(idx);
    matName = mat->getType();
    this->inventory_.removeItem(idx);
    std::cout << " successfully unequiped " << matName << " materia." << std::endl;
}

void Character::use(int idx, ICharacter& target) {
    this->annonce();
    if (idx < 0 || static_cast<size_t>(idx) >= this->inventory_.getSize()) {
        std::cout << " tried to use a non-existent item." << std::endl;
        return ;
    }
    this->inventory_.itemAt(idx)->use(target);
}