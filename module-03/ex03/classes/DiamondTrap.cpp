#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("DiamondTrap_clap_name"), FragTrap("DiamondTrap"), ScavTrap("DiamondTrap") {
	std::cout << C_CYAN << "(DiamondTrap) " << C_RESET << "DiamondTrap default constructor called." << std::endl;
	this->name_ = "DiamondTrap";
    this->MAX_HIT_PTS_ = DF_HIT_PTS_;
    this->hit_pts_ = MAX_HIT_PTS_;
    this->energy_pts_ = DF_ENERGY_PTS_;
    this->atk_dmg_ = DF_ATK_DMG_;
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
	std::cout << C_CYAN << "(DiamondTrap) " << C_RESET << "DiamondTrap name constructor called." << std::endl;
    this->name_ = name;
    this->MAX_HIT_PTS_ = DF_HIT_PTS_;
    this->hit_pts_ = MAX_HIT_PTS_;
    this->energy_pts_ = DF_ENERGY_PTS_;
    this->atk_dmg_ = DF_ATK_DMG_;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy): ClapTrap(copy), FragTrap(copy), ScavTrap(copy) {
	std::cout << C_CYAN << "(DiamondTrap) " << C_RESET << "DiamondTrap copy constructor called." << std::endl;
	this->name_ = copy.name_;
	ClapTrap::name_ = this->name_ + "_clap_name";
	this->MAX_HIT_PTS_ = copy.MAX_HIT_PTS_;
	this->hit_pts_ = copy.hit_pts_;
	this->energy_pts_ = copy.energy_pts_;
	this->atk_dmg_ = copy.atk_dmg_;
}

DiamondTrap::~DiamondTrap() {
	std::cout << C_CYAN << "(DiamondTrap) " << C_RESET << this->name_ << " was not the impostor." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& assign) {
	if (this == &assign)
		return *this;
	this->name_ = assign.name_;
	ClapTrap::name_ = this->name_ + "_clap_name";
	this->MAX_HIT_PTS_ = assign.MAX_HIT_PTS_;
	this->hit_pts_ = assign.hit_pts_;
	this->energy_pts_ = assign.energy_pts_;
	this->atk_dmg_ = assign.atk_dmg_;
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << C_CYAN << "(DiamondTrap) " << C_RESET << this->name_ << " " << ClapTrap::name_ << std::endl;
}
