#include "./Span.hpp"

Span::Span(unsigned int size):
	size_(size) {
		this->arr_.reserve(this->size_);
}

Span::Span(const Span& copy):
	size_(copy.size_),
	arr_(copy.arr_) {
		this->arr_.reserve(this->size_);
}

const Span& Span::operator=(const Span& assign) {
	if (this == &assign)
		return *this;
	this->size_ = assign.size_;
	this->arr_ = assign.arr_;
	this->arr_.reserve(this->size_);
	return *this;
}

Span::~Span() {
	this->arr_.clear();
}

void Span::addNumber(int nb) {
	if(this->arr_.size() >= this->size_) throw std::runtime_error("span is full");
	this->arr_.push_back(nb);
}

unsigned int Span::shortestSpan() const {
	if (this->arr_.size() < 2)
		throw std::runtime_error("not enough span items to compare");
	long rslt = INT_MAX;
	long tmp;
	for(std::vector<int>::const_iterator i = this->arr_.begin(); i != this->arr_.end(); i++) {
		for(std::vector<int>::const_iterator j = this->arr_.begin(); j < this->arr_.end(); j++) {
			if (i == j) continue;
			if ((tmp = std::abs(static_cast<long>(*i) - static_cast<long>(*j))) < rslt)
				rslt = tmp;
		}
	}
	return rslt;
}

unsigned int Span::longestSpan() const {
	if (this->arr_.size() < 2)
		throw std::runtime_error("not enough span items to compare");
	long rslt = 0;
	long tmp;
	for(std::vector<int>::const_iterator i = this->arr_.begin(); i != this->arr_.end(); i++) {
		for(std::vector<int>::const_iterator j = this->arr_.begin(); j < this->arr_.end(); j++) {
			if (i == j) continue;
			if ((tmp = std::abs(static_cast<long>(*i) - static_cast<long>(*j))) > rslt)
				rslt = tmp;
		}
	}
	return rslt;
}

void Span::fill(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	for(std::vector<int>::iterator it = first; it != last; it++) {
		this->addNumber(std::rand());
	}
}

std::vector<int>::iterator Span::begin() { return this->arr_.begin(); }
std::vector<int>::iterator Span::end() { return this->arr_.end(); }
