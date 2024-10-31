#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>
# include "../utils/colors.h"

# ifndef uint
#  define uint unsigned int
# endif

class ClapTrap {
    protected:
        static const uint MAX_HIT_PTS_ = 10;
        static const uint DF_HIT_PTS_ = MAX_HIT_PTS_;
        static const uint DF_ENERGY_PTS_ = 10;
        static const uint DF_ATK_DMG_ = 0;
        std::string name_;
        uint hit_pts_;
        uint energy_pts_;
        uint atk_dmg_;
        bool is_dead_();
        bool has_energy_();
    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& copy);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& assign);
        const std::string& getName();
        uint getHitPts();
        uint getEnergyPts();
        uint getAtkDmg();
        void attack(const std::string& target);
        void takeDamage(uint amount);
        void beRepaired(uint amount);
};

#endif