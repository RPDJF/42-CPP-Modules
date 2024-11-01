#include "./Character.hpp"

void Character::annonce() {
    std::cout << C_YELLOW << this->name_ << C_RESET;
}

Character::Character(): name_("Bob"), inventory_(0) {}

Character::Character(const std::string& name): name_(name), inventory_(0) {}

Character::Character(const Character& copy): name_(copy.name_), inventory_(copy.inventory_);

Character::~Character() { /* Very useful code, don't touch it */}

Character& Character::operator=(const Character& assign) {
    if (this == assign)
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
    if (this->inventory_.size() >= 4) {
        std::cout << "'s inventory is already " << C_RED << "full of materia" << C_RESET << "\n"
        << C_YELLOW << "unequip" << C_RESET << "some materia and try again." << std::endl;
        return;
    }
    this->inventory_.push_back(m);
    std::cout << " equiped " << m->getType() << " materia." << std::endl;
}

void Character::unequip(int idx) {
    AMateria *mat;
    std::string matName;

    this->annonce();
    if (this->inventory_.size() >= idx) {
        std::cout << C_RED << " you can't unequip an item you don't have !" << C_RESET << std::endl;
        return;
    }
    mat = this->inventory_.at(idx);
    matName = mat->getType();
    this->inventory_.erase(this->inventory_.begin() + idx);
    std::cout << " successfully unequiped " << matName << " materia." << std::endl;
}