#include "ScavTrap.hpp"

//  Constructors
ScavTrap::ScavTrap(): ClapTrap("ScavTrap") {
    std::cout   << C_MAGENTA << "(ScavTrap) " << C_RESET << "ScavTrap default constructor has been called."
                << std::endl;
    this->hit_pts_ = MAX_HIT_PTS_;
    this->energy_pts_ = DF_ENERGY_PTS_;
    this->atk_dmg_ = DF_ATK_DMG_;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name) {
    std::cout   << C_MAGENTA << "(ScavTrap) " << C_RESET << "ScavTrap name constructor has been called."
                << std::endl;
    this->hit_pts_ = MAX_HIT_PTS_;
    this->energy_pts_ = DF_ENERGY_PTS_;
    this->atk_dmg_ = DF_ATK_DMG_;
}

ScavTrap::ScavTrap(const ScavTrap& copy): ClapTrap(copy) {
    std::cout   << C_MAGENTA << "(ScavTrap) " << C_RESET << "ScavTrap copy constructor has been called."
                << std::endl;
    this->name_ = copy.name_;
    this->hit_pts_ = copy.hit_pts_;
    this->energy_pts_ = copy.energy_pts_;
    this->atk_dmg_ = copy.atk_dmg_;
}

//  Deconstructors
ScavTrap::~ScavTrap() {
    std::cout   << C_MAGENTA << "(ScavTrap) " << C_RESET << this->name_ << " was the impostor."
                << std::endl;
}

//  Inherited functions overload
void ScavTrap::attack(const std::string& target) {
    if (this->is_dead_() || !this->has_energy_()) {
        std::cout   << C_MAGENTA << "(ScavTrap) " << C_RESET
                    << this->name_ << " couldn't attack."
                    << std::endl;
        return ;
    }
    this->energy_pts_--;
    std::cout   << C_MAGENTA << "(ScavTrap) " << C_RESET
                << this->name_ << " has attacked " << target << ", causing " << atk_dmg_ << " damage points!\n"
                << this->name_ << " has now " << this->energy_pts_ << " energy points."
                << std::endl;
}

//  Operator overloads
//      Equal operator
ScavTrap& ScavTrap::operator=(const ScavTrap& assign) {
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

//  Member functions
void ScavTrap::guardGate() {
    if (this->is_dead_() || !this->has_energy_()) {
        std::cout   << C_MAGENTA << "(ScavTrap) " << C_RESET
                    << this->name_ << " couldn't guard gate."
                    << std::endl;
        return ;
    }
    std::cout   << C_MAGENTA << "(ScavTrap) " << C_RESET << this->name_ << " has entered gate keeper mode."
                << std::endl;
}