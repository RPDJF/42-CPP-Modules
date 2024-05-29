#include "ScavTrap.hpp"

//  Constructors
ScavTrap::ScavTrap(): ClapTrap("ScavTrap") {
    std::cout   << "(ScavTrap) " << "ScavTrap default constructor called."
                << std::endl;
    this->MAX_HIT_PTS_ = 100;
    this->hit_pts_ = MAX_HIT_PTS_;
    this->energy_pts_ = 50;
    this->atk_dmg_ = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
    std::cout   << "(ScavTrap) " << "ScavTrap name constructor called."
                << std::endl;
    this->MAX_HIT_PTS_ = 100;
    this->hit_pts_ = MAX_HIT_PTS_;
    this->energy_pts_ = 50;
    this->atk_dmg_ = 20;
}

ScavTrap::ScavTrap(ScavTrap& copy): ClapTrap(copy) {
    std::cout   << "(ScavTrap) " << "ScavTrap copy constructor called."
                << std::endl;
    this->name_ = copy.name_;
    this->MAX_HIT_PTS_ = copy.MAX_HIT_PTS_;
    this->hit_pts_ = copy.hit_pts_;
    this->energy_pts_ = copy.energy_pts_;
    this->atk_dmg_ = copy.atk_dmg_;
}

//  Deconstructors
ScavTrap::~ScavTrap() {
    std::cout   << "(ScavTrap) " << this->name_ << " was the impostor."
                << std::endl;
}

//  Operator overloads
//      Equal operator
ScavTrap& ScavTrap::operator=(ScavTrap& assign) {
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
    std::cout   << "(ScavTrap) " << this->name_ << " has entered gate keeper mode."
                << std::endl;
}