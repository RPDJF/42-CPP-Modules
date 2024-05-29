#include "ClapTrap.hpp"

//  Constructors
ClapTrap::ClapTrap(): MAX_HIT_PTS_(10) {
    name_ = "ClapTrap";
    hit_pts_ = MAX_HIT_PTS_;
    energy_pts_ = 10;
    atk_dmg_ = 6;
}

ClapTrap::ClapTrap(ClapTrap& copy): MAX_HIT_PTS_(10) {
    this->name_ = copy.name_;
    this->hit_pts_ = copy.hit_pts_;
    this->energy_pts_ = copy.energy_pts_;
    this->atk_dmg_ = copy.atk_dmg_;
}

ClapTrap::ClapTrap(std::string name): MAX_HIT_PTS_(10) {
    name_ = name;
    hit_pts_ = 10;
    energy_pts_ = 10;
    atk_dmg_ = 6;
}

//  Deconstructors
ClapTrap::~ClapTrap() {
    std::cout   << this->name_ << " has be abandoned into the void."
                << std::endl;
}

//  Operator overloads
//      Equal operator
ClapTrap& ClapTrap::operator=(ClapTrap& assign) {
    if (this == &assign)
        return *this;
    else {
        this->name_ = assign.name_;
        this->hit_pts_ = assign.hit_pts_;
        this->energy_pts_ = assign.energy_pts_;
        this->atk_dmg_ = assign.atk_dmg_;
        return *this;
    }
}

//  Getters member functions
std::string ClapTrap::getName() {
    return this->name_;
}

unsigned int ClapTrap::getHitPts() {
    return this->hit_pts_;
}

unsigned int ClapTrap::getEnergyPts() {
    return this->energy_pts_;
}

unsigned int ClapTrap::getAtkDmg() {
    return this->atk_dmg_;
}

//  Member functions
bool ClapTrap::is_dead_() {
    if (this->hit_pts_ == 0) {
        std::cout   << this->name_ << " is K.O."
                    << std::endl;
        return true;
    }
    return false;
}

void ClapTrap::attack(const std::string& target) {
    if (this->is_dead_()) {
        std::cout   << this->name_ << " couldn't attack."
                    << std::endl;
    } else if (energy_pts_ == 0) {
        std::cout   << this->name_ << " has no more energy points.\n"
                    << this->name_ << " couldn't attack."
                    << std::endl;
    } else {
        this->energy_pts_--;
        std::cout   << this->name_ << " has attacked " << target << ", causing " << atk_dmg_ << " damage points!\n"
                    << this->name_ << " has now " << this->energy_pts_ << " energy points."
                    << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->is_dead_()) {
        std::cout   << this->name_ << " has already fainted and could not be targeted for damage."
                    << std::endl;
    } else if (this->hit_pts_ <= amount) {
        std::cout   << this->name_ << " has lost " << amount << " HP.\n"
                    << this->name_ << " has no more HP left.\n"
                    << this->name_ << " fainted."
                    << std::endl;
        this->hit_pts_ = 0;
    } else {
        this->hit_pts_ -= amount;
        std::cout   << this->name_ << " has lost " << amount << " HP.\n"
                    << this->name_ << " has now " << this->hit_pts_ << " HP left on " << this->MAX_HIT_PTS_
                    << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->is_dead_()) {
        std::cout   << this->name_ << " couldn't be repaired."
                    << std::endl;
    } else if (energy_pts_ == 0) {
        std::cout   << this->name_ << " has no more energy points.\n"
                    << this->name_ << " couldn't be repaired."
                    << std::endl;
    } else {
        this->energy_pts_--;
        if (amount + this->hit_pts_ > MAX_HIT_PTS_) {
            std::cout   << this->name_ << " has been healed of " << this->MAX_HIT_PTS_ - this->hit_pts_ << " HP.\n"
                        << this->name_ << " has now " << this->MAX_HIT_PTS_ << " HP and " << this->energy_pts_ << " energy points."
                        << std::endl;
            this->hit_pts_ = MAX_HIT_PTS_;
        } else {
            this->hit_pts_ += amount;
            std::cout   << this->name_ << " has been healed of " << amount << " HP.\n"
                        << this->name_ << " has now " << this->hit_pts_ << " HP and " << this->energy_pts_ << " energy points."
                        << std::endl;
        }
    }
}