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
	std::sort(this->arr_.begin(), this->arr_.end());
	std::vector<long int> rslt(this->arr_.size());
	std::adjacent_difference(this->arr_.begin(), this->arr_.end(), rslt.begin());
	for(std::vector<long int>::iterator i = rslt.begin(); i != rslt.end(); i++)
		*i = std::abs(*i);
	return *std::min_element(rslt.begin() + 1, rslt.end());
}

unsigned int Span::longestSpan() const {
	if (this->arr_.size() < 2)
		throw std::runtime_error("not enough span items to compare");
	std::sort(this->arr_.begin(), this->arr_.end());
	long biggestElem = (long)*std::max_element(this->arr_.begin(), this->arr_.end());
	long smallestElem = (long)*std::min_element(this->arr_.begin(), this->arr_.end());
	return biggestElem - smallestElem;
}

void Span::fill(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	for(std::vector<int>::iterator it = first; it != last; it++) {
		this->addNumber(std::rand());
	}
}

std::vector<int>::iterator Span::begin() { return this->arr_.begin(); }
std::vector<int>::iterator Span::end() { return this->arr_.end(); }
