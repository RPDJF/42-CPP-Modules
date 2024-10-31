#include "classes/DiamondTrap.hpp"
#include <iostream>

int main(void) {

	ClapTrap	mvillarr("Maria");
	ScavTrap	ilyanar("Ilkay");
	FragTrap	fclivaz("Fabien");
	DiamondTrap	smuravye("Stan");

	// ...Whatever this is.
	mvillarr.beRepaired(30);
	ilyanar.guardGate();
	mvillarr.attack("Ilkay");
	ilyanar.takeDamage(5);
	ilyanar.attack("Maria");
	mvillarr.takeDamage(20);
	mvillarr.beRepaired(3);
	ilyanar.attack("Maria");
	mvillarr.takeDamage(20);
	mvillarr.beRepaired(1);
	mvillarr.beRepaired(1);
	mvillarr.beRepaired(1);
	mvillarr.beRepaired(1);
	mvillarr.beRepaired(1);
	mvillarr.beRepaired(1);
	mvillarr.beRepaired(1);
	mvillarr.beRepaired(1);
	mvillarr.beRepaired(1);
	mvillarr.beRepaired(1);
	fclivaz.highFivesGuys();
	ilyanar.attack("Maria");
	mvillarr.takeDamage(20);
	fclivaz.attack("Ilkay");
	ilyanar.takeDamage(30);
	ilyanar.attack("Fabien");
	fclivaz.takeDamage(20);
	fclivaz.attack("Ilkay");
	ilyanar.takeDamage(30);
	ilyanar.attack("Fabien");
	fclivaz.takeDamage(20);
	fclivaz.attack("Ilkay");
	ilyanar.takeDamage(30);
	ilyanar.attack("Fabien");
	fclivaz.takeDamage(20);
	fclivaz.attack("Ilkay");
	ilyanar.takeDamage(30);
	fclivaz.highFivesGuys();
	smuravye.attack("Fabien");
	fclivaz.takeDamage(30);
	smuravye.whoAmI();
	smuravye.guardGate();
	smuravye.highFivesGuys();
	return 0;
}
