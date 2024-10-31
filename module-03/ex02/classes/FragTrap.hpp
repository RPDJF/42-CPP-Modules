#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap& copy);
        ~FragTrap();
        FragTrap& operator=(FragTrap &assign);
        void attack(const std::string& target);
        void highFivesGuys();
};

#endif