#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "./ClapTrap.hpp"
# include "./FragTrap.hpp"
# include "./ScavTrap.hpp"

class	DiamondTrap: public FragTrap, public ScavTrap {
	private:
		std::string name_;
	protected:
        static const uint DF_HIT_PTS_ = FragTrap::DF_HIT_PTS_;
        static const uint DF_ENERGY_PTS_ = ScavTrap::DF_ENERGY_PTS_;
        static const uint DF_ATK_DMG_ = FragTrap::DF_ATK_DMG_;
	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		~DiamondTrap();
		void whoAmI();
		using ScavTrap::attack;
};

#endif