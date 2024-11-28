#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): size_(0) {
	for (unsigned char i = 0; i < SRC_SIZE; i++) {
		this->arr_[i] = 0;
	}
}

MateriaSource::MateriaSource(const MateriaSource& copy): size_(copy.size_) {
	for (unsigned char i = 0; i < SRC_SIZE; i++) {
		this->arr_[i] = copy.arr_[i];
	}
}

MateriaSource::~MateriaSource() {
	for (unsigned char i = 0; i < this->size_; i++) {
		delete this->arr_[i];
	}
}

const MateriaSource& MateriaSource::operator=(const MateriaSource& assign) {
	if (this == &assign)
		return *this;
	this->size_ = assign.size_;
	for (unsigned char i = 0; i < SRC_SIZE; i++) {
		delete this->arr_[i];
		this->arr_[i] = assign.arr_[i] ? assign.arr_[i]->clone() : 0;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (this->size_ < SRC_SIZE) {
		this->arr_[this->size_++] = m;
	}
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (unsigned char i = 0; i < this->size_; i++) {
		if (this->arr_[i]->getType() == type) {
			return this->arr_[i]->clone();
		}
	}
	return 0;
}