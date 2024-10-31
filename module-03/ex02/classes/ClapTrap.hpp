#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# ifndef uint
#  define uint unsigned int
# endif

class ClapTrap {
    protected:
        std::string name_;
        uint hit_pts_;
        uint MAX_HIT_PTS_;
        uint energy_pts_;
        uint atk_dmg_;
        bool is_dead_();
        bool has_energy_();
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap& copy);
        ~ClapTrap();
        ClapTrap& operator=(ClapTrap& assign);
        std::string getName();
        uint getHitPts();
        uint getEnergyPts();
        uint getAtkDmg();
        void attack(const std::string& target);
        void takeDamage(uint amount);
        void beRepaired(uint amount);
};

#endif