#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "./ICharacter.hpp"
# include "../utils/colors.h"

class AMateria {
    protected:
        const std::string& type;
    public:
        AMateria(const std::string& type);
        AMateria(const AMateria& copy);
        ~AMateria();
        AMateria& operator=(const AMateria& assign);
        const std::string& getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif