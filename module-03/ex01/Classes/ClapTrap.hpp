#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
    protected:
        std::string name_;
        unsigned int hit_pts_;
        unsigned int MAX_HIT_PTS_;
        unsigned int energy_pts_;
        unsigned int atk_dmg_;
        bool is_dead_();
        bool has_energy_();
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap& copy);
        ~ClapTrap();
        ClapTrap& operator=(ClapTrap& assign);
        std::string getName();
        unsigned int getHitPts();
        unsigned int getEnergyPts();
        unsigned int getAtkDmg();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif