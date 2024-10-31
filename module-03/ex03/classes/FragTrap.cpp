#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("FragTrap") {
    std::cout   << C_GREEN << "(FragTrap) " << C_RESET << "FragTrap default constructor has been called."
                << std::endl;
    this->MAX_HIT_PTS_ = DF_HIT_PTS_;
    this->hit_pts_ = MAX_HIT_PTS_;
    this->energy_pts_ = DF_ENERGY_PTS_;
    this->atk_dmg_ = DF_ATK_DMG_;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name) {
    std::cout   << C_GREEN << "(FragTrap) " << C_RESET << "FragTrap name constructor has been called."
                << std::endl;
    this->MAX_HIT_PTS_ = DF_HIT_PTS_;
    this->hit_pts_ = MAX_HIT_PTS_;
    this->energy_pts_ = DF_ENERGY_PTS_;
    this->atk_dmg_ = DF_ATK_DMG_;
}

FragTrap::FragTrap(const FragTrap& copy): ClapTrap(copy) {
    std::cout   << C_GREEN << "(FragTrap) " << C_RESET << "FragTrap copy constructor has been called."
                << std::endl;
    this->name_ = copy.name_;
    this->MAX_HIT_PTS_ = copy.MAX_HIT_PTS_;
    this->hit_pts_ = copy.hit_pts_;
    this->energy_pts_ = copy.energy_pts_;
    this->atk_dmg_ = copy.atk_dmg_;
}

FragTrap::~FragTrap() {
    std::cout   << C_GREEN << "(FragTrap) " << C_RESET << this->name_ << " was the impostor."
                << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &assign) {
    if (this == &assign)
        return *this;
    this->name_ = assign.name_;
    this->MAX_HIT_PTS_ = assign.MAX_HIT_PTS_;
    this->hit_pts_ = assign.hit_pts_;
    this->energy_pts_ = assign.energy_pts_;
    this->atk_dmg_ = assign.atk_dmg_;
    return *this;
}

void FragTrap::attack(const std::string& target) {
    if (this->is_dead_() || !this->has_energy_()) {
        std::cout   << C_GREEN << "(FragTrap) " << C_RESET
                    << this->name_ << " couldn't attack."
                    << std::endl;
        return ;
    }
    this->energy_pts_--;
    std::cout   << C_GREEN << "(FragTrap) " << C_RESET
                << this->name_ << " has attacked " << target << ", causing " << atk_dmg_ << " damage points!\n"
                << this->name_ << " has now " << this->energy_pts_ << " energy points."
                << std::endl;
}

void FragTrap::highFivesGuys() {
    if (this->is_dead_() || !this->has_energy_()) {
        std::cout   << C_GREEN << "(FragTrap) " << C_RESET << this->name_ << " couldn't ask for an highfive."
                    << std::endl;
        return;
    }
    std::cout   << C_GREEN << "(FragTrap) " << C_RESET << this->name_ << " asked for an highfive !"
                << std::endl;
}