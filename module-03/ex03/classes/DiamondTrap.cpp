#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("DiamondTrap_clap_name"), FragTrap("DiamondTrap"), ScavTrap("DiamondTrap") {
	std::cout << C_CYAN << "(DiamondTrap) " << C_RESET << "DiamondTrap default constructor called." << std::endl;
	this->name_ = "DiamondTrap";
	this->hit_pts_ = DF_HIT_PTS_;
	this->energy_pts_ = DF_ENERGY_PTS_;
	this->atk_dmg_ = DF_ATK_DMG_;
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
	std::cout << C_CYAN << "(DiamondTrap) " << C_RESET << "DiamondTrap name constructor called." << std::endl;
	this->name_ = name;
	this->hit_pts_ = DF_HIT_PTS_;
	this->energy_pts_ = DF_ENERGY_PTS_;
	this->atk_dmg_ = DF_ATK_DMG_;
}

DiamondTrap::~DiamondTrap() {
	std::cout << C_CYAN << "(DiamondTrap) " << C_RESET << this->name_ << " was not the impostor." << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << C_CYAN << "(DiamondTrap) " << C_RESET << this->name_ << " " << ClapTrap::name_ << std::endl;
}
