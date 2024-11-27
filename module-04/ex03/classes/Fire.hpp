#ifndef FIRE_HPP
# define FIRE_HPP

#include "./AMateria.hpp"

class Fire: public AMateria {
    public:
        Fire();
        Fire(const Fire& copy);
        ~Fire();
        Fire& operator=(const Fire& assign);
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif