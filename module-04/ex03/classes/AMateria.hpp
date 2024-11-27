#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "../utils/colors.h"

class ICharacter;

class AMateria {
    protected:
        const std::string type_;
		bool isEquiped_;
    public:
        AMateria(const std::string& type);
        AMateria(const AMateria& copy);
        virtual ~AMateria();
        AMateria& operator=(const AMateria& assign);
        const std::string& getType() const;
		bool isEquiped() const;
		void setEquip(bool status);
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif