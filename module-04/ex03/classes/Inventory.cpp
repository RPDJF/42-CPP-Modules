#include "Inventory.hpp"

t_floor_node* Inventory::floor_ = 0;
unsigned int Inventory::inventoryInstances_ = 0;

Inventory::Inventory(): size_(0) {
	Inventory::inventoryInstances_++;
    for (unsigned int i = 0; i < INV_SIZE; i++)
        this->arr_[i] = 0;
}

Inventory::Inventory(const Inventory& copy) {
	Inventory::inventoryInstances_++;
    this->size_ = copy.size_;
    for (unsigned int i = 0; i < INV_SIZE; i++)
        if (copy.arr_[i] != 0)
            this->arr_[i] = copy.arr_[i]->clone();
        else
            this->arr_[i] = 0;
}

Inventory::~Inventory() {
	if (Inventory::inventoryInstances_)
		Inventory::inventoryInstances_--;
	if (!Inventory::inventoryInstances_) {
		std::cout << "once" << std::endl;
		t_floor_node *node = Inventory::floor_;
		t_floor_node *next;
		while (node) {
			next = node->next;
			delete node->materia;
			delete node;
			node = next;
		}
		Inventory::floor_ = 0;
	}
}

const Inventory& Inventory::operator=(const Inventory& assign) {
    if (this == &assign)
        return *this;
    for (unsigned int i = 0; i < this->size_; i++) {
        arr_[i] = 0;
    }
    this->size_ = assign.size_;
    for (unsigned int i = 0; i < assign.size_; i++) {
        if (assign.arr_[i] !=  0)
            this->arr_[i] = assign.arr_[i]->clone();
    }
    return *this;
}

unsigned int Inventory::getSize() { return this->size_; }

void Inventory::addItem(AMateria* materia) {
    if(this->size_ >= INV_SIZE)
        return ;
    this->arr_[this->size_] = materia;
    this->size_++;
	materia->setEquip(true);
	t_floor_node *dup = Inventory::floor_;
	while (dup && dup->materia != materia) {
		dup = dup->next;
	}
	if (dup)
		return ;
	t_floor_node* node = new t_floor_node;
	node->materia = materia;
	node->next = Inventory::floor_;
	Inventory::floor_ = node;
}

void Inventory::removeItem(unsigned int idx) {
    if (!this->size_ || idx >= this->size_) {
        return ;
	}
	for (unsigned int i = idx; i < this->size_ - 1; ++i) {
		this->arr_[i] = this->arr_[i + 1];
	}
	this->arr_[this->size_ - 1]->setEquip(false);
	this->arr_[this->size_ - 1] = 0;
	this->size_--;
}

AMateria* Inventory::itemAt(unsigned int idx) {
    if (!this->size_ || idx >= this->size_)
        return 0;
    return this->arr_[idx];
}
