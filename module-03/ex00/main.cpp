#include "classes/ClapTrap.hpp"
#include <iostream>

int main(void) {
    ClapTrap George("George");
    ClapTrap claptrap;
    ClapTrap Georgette(George);
    ClapTrap Georgine = claptrap;

    std::cout << "\nGeorge vs Claptrap\n" << std::endl;

    for (int i = 0; i < 20; i++) {
        std::cout << "Round " << i + 1 << std::endl;
        George.attack(claptrap.getName());
        claptrap.takeDamage(George.getAtkDmg());
        claptrap.beRepaired(30);
        claptrap.attack(George.getName());
        George.takeDamage(claptrap.getAtkDmg());
        George.beRepaired(3);
        std::cout << std::endl;
    }

    std::cout << "\nGeorgette vs Georgine\n" << std::endl;

    for (int i = 0; i < 20; i++) {
        std::cout << "Round " << i + 1 << std::endl;
        Georgette.attack(Georgine.getName());
        Georgine.takeDamage(Georgette.getAtkDmg());
        Georgine.beRepaired(30);
        Georgine.attack(Georgette.getName());
        Georgette.takeDamage(Georgine.getAtkDmg());
        Georgette.beRepaired(3);
        std::cout << std::endl;
    }
}