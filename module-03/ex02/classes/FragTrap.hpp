#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class FragTrap: virtual public ClapTrap {
    protected:
        static const uint DF_HIT_PTS_ = 100;
        static const uint DF_ENERGY_PTS_ = 100;
        static const uint DF_ATK_DMG_ = 30;
    public:
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& copy);
        ~FragTrap();
        FragTrap& operator=(const FragTrap &assign);
        void attack(const std::string& target);
        void highFivesGuys();
};

#endif