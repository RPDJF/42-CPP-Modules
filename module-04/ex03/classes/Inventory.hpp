#ifndef INVENTORY_HPP
# define INVENTORY_HPP

# include "./AMateria.hpp"

# define INV_SIZE 4

typedef struct s_floor_node t_floor_node;
typedef struct s_floor_node {
    AMateria *materia;
    t_floor_node* next;
}	t_floor_node;

class Inventory {
    private:
        unsigned int size_;
        AMateria* arr_[INV_SIZE];
        static t_floor_node* floor_;
		static unsigned int inventoryInstances_;
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