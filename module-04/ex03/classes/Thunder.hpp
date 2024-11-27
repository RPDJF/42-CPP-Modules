#ifndef THUNDER_HPP
# define THUNDER_HPP

#include "./AMateria.hpp"

class Thunder: public AMateria {
    public:
        Thunder();
        Thunder(const Thunder& copy);
        ~Thunder();
        Thunder& operator=(const Thunder& assign);
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif