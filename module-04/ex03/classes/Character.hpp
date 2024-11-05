#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "./ICharacter.hpp"
# include "./Inventory.hpp"

class Character: public ICharacter {
    private:
        std::string name_;
        Inventory inventory_;
        void annonce();
    public:
        Character();
        Character(const std::string& name);
        Character(const Character& copy);
        ~Character();
        Character& operator=(const Character& assign);
        const std::string& getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif