#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class ScavTrap: virtual public ClapTrap {
    protected:
        static const uint MAX_HIT_PTS_ = 100;
        static const uint DF_HIT_PTS_ = MAX_HIT_PTS_;
        static const uint DF_ENERGY_PTS_ = 50;
        static const uint DF_ATK_DMG_ = 20;
    public:
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& copy);
        ~ScavTrap();
        ScavTrap& operator=(const ScavTrap& assign);
        void attack(const std::string& target);
        void guardGate();
};

#endif 