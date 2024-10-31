#include "ClapTrap.hpp"

//  Constructors
ClapTrap::ClapTrap() {
    std::cout   << C_YELLOW << "(ClapTrap) " << C_RESET << "ClapTrap default constructor has been called."
                << std::endl;
    this->name_ = "ClapTrap";
    this->MAX_HIT_PTS_ = DF_HIT_PTS_;
    this->hit_pts_ = MAX_HIT_PTS_;
    this->energy_pts_ = DF_ENERGY_PTS_;
    this->atk_dmg_ = DF_ATK_DMG_;
}

ClapTrap::ClapTrap(const std::string& name) {
    std::cout   << C_YELLOW << "(ClapTrap) " << C_RESET << "ClapTrap name constructor has been called."
                << std::endl;
    this->name_ = name;
    this->MAX_HIT_PTS_ = DF_HIT_PTS_;
    this->hit_pts_ = MAX_HIT_PTS_;
    this->energy_pts_ = DF_ENERGY_PTS_;
    this->atk_dmg_ = DF_ATK_DMG_;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
    std::cout   << C_YELLOW << "(ClapTrap) " << C_RESET << "ClapTrap copy constructor has been called."
                << std::endl;
    this->name_ = copy.name_;
    this->MAX_HIT_PTS_ = copy.MAX_HIT_PTS_;
    this->hit_pts_ = copy.hit_pts_;
    this->energy_pts_ = copy.energy_pts_;
    this->atk_dmg_ = copy.atk_dmg_;
}

//  Deconstructors
ClapTrap::~ClapTrap() {
    std::cout   << C_YELLOW << "(ClapTrap) " << C_RESET << this->name_ << " was not the impostor."
                << std::endl;
}

//  Operator overloads
//      Equal operator
ClapTrap& ClapTrap::operator=(const ClapTrap& assign) {
    if (this == &assign)
        return *this;
    this->name_ = assign.name_;
    this->MAX_HIT_PTS_ = assign.MAX_HIT_PTS_;
    this->hit_pts_ = assign.hit_pts_;
    this->energy_pts_ = assign.energy_pts_;
    this->atk_dmg_ = assign.atk_dmg_;
    return *this;
}

//  Getters member functions
const std::string& ClapTrap::getName() {
    return this->name_;
}

uint ClapTrap::getHitPts() {
    return this->hit_pts_;
}

uint ClapTrap::getEnergyPts() {
    return this->energy_pts_;
}

uint ClapTrap::getAtkDmg() {
    return this->atk_dmg_;
}

//  Member functions
bool ClapTrap::is_dead_() {
    if (this->hit_pts_ == 0) {
        std::cout   << C_YELLOW << "(ClapTrap) " << C_RESET
                    << this->name_ << " is K.O."
                    << std::endl;
        return true;
    }
    return false;
}

bool ClapTrap::has_energy_() {
    if (this->energy_pts_ == 0) {
        std::cout   << C_YELLOW << "(ClapTrap) " << C_RESET
                    << this->name_ << " has no more energy points."
                    << std::endl;
        return false;
    }
    return true;
}

void ClapTrap::attack(const std::string& target) {
    if (this->is_dead_() || !this->has_energy_()) {
        std::cout   << C_YELLOW << "(ClapTrap) " << C_RESET
                    << this->name_ << " couldn't attack."
                    << std::endl;
        return ;
    }
    this->energy_pts_--;
    std::cout   << C_YELLOW << "(ClapTrap) " << C_RESET
                << this->name_ << " has attacked " << target << ", causing " << atk_dmg_ << " damage points!\n"
                << this->name_ << " has now " << this->energy_pts_ << " energy points."
                << std::endl;
}

void ClapTrap::takeDamage(uint amount) {
    if (this->is_dead_()) {
        std::cout   << C_YELLOW << "(ClapTrap) " << C_RESET
                    << this->name_ << " has already fainted and could not be targeted for damage."
                    << std::endl;
    } else if (this->hit_pts_ <= amount) {
        std::cout   << C_YELLOW << "(ClapTrap) " << C_RESET
                    << this->name_ << " has lost " << amount << " HP.\n"
                    << this->name_ << " has no more HP left.\n"
                    << this->name_ << " fainted."
                    << std::endl;
        this->hit_pts_ = 0;
    } else {
        this->hit_pts_ -= amount;
        std::cout   << C_YELLOW << "(ClapTrap) " << C_RESET
                    << this->name_ << " has lost " << amount << " HP.\n"
                    << this->name_ << " has now " << this->hit_pts_ << " HP left on " << this->MAX_HIT_PTS_ << " HP"
                    << std::endl;
    }
}

void ClapTrap::beRepaired(uint amount) {
    if (this->is_dead_() || !this->has_energy_()) {
        std::cout   << C_YELLOW << "(ClapTrap) " << C_RESET
                    << this->name_ << " couldn't be repaired."
                    << std::endl;
        return ;
    }
    this->energy_pts_--;
    if (amount + this->hit_pts_ > MAX_HIT_PTS_) {
        std::cout   << C_YELLOW << "(ClapTrap) " << C_RESET
                    << this->name_ << " has been healed of " << this->MAX_HIT_PTS_ - this->hit_pts_ << " HP.\n"
                    << this->name_ << " has now " << this->MAX_HIT_PTS_ << " HP and " << this->energy_pts_ << " energy points."
                    << std::endl;
        this->hit_pts_ = MAX_HIT_PTS_;
    } else {
        this->hit_pts_ += amount;
        std::cout   << C_YELLOW << "(ClapTrap) " << C_RESET
                    << this->name_ << " has been healed of " << amount << " HP.\n"
                    << this->name_ << " has now " << this->hit_pts_ << " HP and " << this->energy_pts_ << " energy points."
                    << std::endl;
    }
}