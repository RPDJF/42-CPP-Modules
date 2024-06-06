#include "classes/FragTrap.hpp"
#include <iostream>

int main(void) {
    FragTrap Neon("Neon");
    FragTrap claptrap;
    FragTrap Neon2(Neon);
    FragTrap claptrap2 = claptrap;

    std::cout << "\nNeon vs Claptrap\n" << std::endl;

    for (int i = 0; i < 20; i++) {
        std::cout << "Round " << i + 1 << std::endl;
        Neon.highFivesGuys();
        Neon.attack(claptrap.getName());
        claptrap.takeDamage(Neon.getAtkDmg());
        claptrap.beRepaired(30);
        claptrap.attack(Neon.getName());
        Neon.takeDamage(claptrap.getAtkDmg());
        Neon.beRepaired(3);
        std::cout << std::endl;
    }

    std::cout << "\nNeon2 vs claptrap2\n" << std::endl;

    for (int i = 0; i < 20; i++) {
        std::cout << "Round " << i + 1 << std::endl;
        Neon2.highFivesGuys();
        Neon2.attack(claptrap2.getName());
        claptrap2.takeDamage(Neon2.getAtkDmg());
        claptrap2.beRepaired(30);
        claptrap2.attack(Neon2.getName());
        Neon2.takeDamage(claptrap2.getAtkDmg());
        Neon2.beRepaired(3);
        std::cout << std::endl;
    }
}