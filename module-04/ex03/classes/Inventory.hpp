#ifndef INVENTORY_HPP
# define INVENTORY_HPP

# include "./AMateria.hpp"

# define INV_SIZE 4
# ifndef nullptr
#  define nullptr 0
# endif

class Inventory {
    private:
        unsigned int size_;
        AMateria* arr_[INV_SIZE];
    public:
        Inventory();
        Inventory(const Inventory& copy);
        ~Inventory();
        const Inventory& operator=(const Inventory& assign);
        unsigned int getSize();
        void addItem(AMateria* materia);
        void removeItem(unsigned int idx);
        AMateria* itemAt(unsigned int idx);
};

#endif