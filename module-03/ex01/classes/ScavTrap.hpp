#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class ScavTrap: public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap& copy);
        ~ScavTrap();
        ScavTrap& operator=(ScavTrap& assign);
        void attack(const std::string& target);
        void guardGate();
};

#endif 