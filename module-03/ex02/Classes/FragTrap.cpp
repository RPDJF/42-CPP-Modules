#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("FragTrap") {
    std::cout   << "(FragTrap) " << "FragTrap default constructor has been called."
                << std::endl;
    MAX_HIT_PTS_= 100;
    hit_pts_ = MAX_HIT_PTS_;
    energy_pts_ = 100;
    atk_dmg_ = 30;

}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
    std::cout   << "(FragTrap) " << "FragTrap parameter constructor has been called."
                << std::endl;
    MAX_HIT_PTS_= 100;
    hit_pts_ = MAX_HIT_PTS_;
    energy_pts_ = 100;
    atk_dmg_ = 30;
}

FragTrap::FragTrap(FragTrap& assign): ClapTrap(assign) {
    std::cout   << "(FragTrap) " << "FragTrap copy constructor has been called."
                << std::endl;
    name_ = assign.name_;
    MAX_HIT_PTS_ = assign.MAX_HIT_PTS_;
    hit_pts_ = assign.hit_pts_;
    energy_pts_ = assign.energy_pts_;
    atk_dmg_ = assign.atk_dmg_;
}

FragTrap::~FragTrap() {
    std::cout   << "(FragTrap) " << this->name_ << " was the impostor."
                << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap &assign) {
    if (this == &assign)
        return *this;
    name_ = assign.name_;
    MAX_HIT_PTS_ = assign.MAX_HIT_PTS_;
    hit_pts_ = assign.hit_pts_;
    energy_pts_ = assign.energy_pts_;
    atk_dmg_ = assign.atk_dmg_;
    return *this;
}

void FragTrap::highFivesGuys() {
    if (this->is_dead_() || !this->has_energy_()) {
        std::cout   << "(FragTrap) " << this->name_ << " couldn't ask for an highfive."
                    << std::endl;
        return;
    }
    std::cout   << "(FragTrap) " << this->name_ << " asked for an highfive !"
                << std::endl;
}