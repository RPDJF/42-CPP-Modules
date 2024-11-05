#include "Inventory.hpp"

Inventory::Inventory(): size_(0) {
    for (unsigned int i = 0; i < INV_SIZE; i++)
        this->arr_[i] = nullptr;
}

Inventory::Inventory(const Inventory& copy) {
    this->size_ = copy.size_;
    for (unsigned int i = 0; i < INV_SIZE; i++)
        if (copy.arr_[i] != nullptr)
            this->arr_[i] = copy.arr_[i]->clone();
        else
            this->arr_[i] = nullptr;
}

Inventory::~Inventory() {
    /*for (unsigned int i = 0; i < INV_SIZE; i++)
        delete arr_[i];*/
}

const Inventory& Inventory::operator=(const Inventory& assign) {
    if (this == &assign)
        return *this;
    for (unsigned int i = 0; i < this->size_; i++) {
        /*delete arr_[i];*/
        arr_[i] = nullptr;
    }
    this->size_ = assign.size_;
    for (unsigned int i = 0; i < assign.size_; i++) {
        if (assign.arr_[i] !=  nullptr)
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
}

void Inventory::removeItem(unsigned int idx) {
    if (!this->size_ || idx >= this->size_)
        return ;
    this->size_--;
    for(unsigned int i = idx; i < this->size_; i++)
        this->arr_[i] = this->arr_[i + 1];
    this->arr_[this->size_] = nullptr;
}

AMateria* Inventory::itemAt(unsigned int idx) {
    if (!this->size_ || idx >= this->size_)
        return nullptr;
    return this->arr_[idx];
}
