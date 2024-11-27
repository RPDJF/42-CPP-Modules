#ifndef POISON_HPP
# define POISON_HPP

#include "./AMateria.hpp"

class Poison: public AMateria {
    public:
        Poison();
        Poison(const Poison& copy);
        ~Poison();
        Poison& operator=(const Poison& assign);
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif