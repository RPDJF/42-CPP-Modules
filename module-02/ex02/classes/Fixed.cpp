#include "Fixed.hpp"

//	CONSTRUCTORS
Fixed::Fixed() {
	this->raw_bits_ = 0;
}

Fixed::Fixed(const Fixed &fixed) {
	this->raw_bits_ = fixed.raw_bits_;
}

Fixed::Fixed(int value) {
	this->raw_bits_ = value << this->fractionnal_bits_;
}

Fixed::Fixed(float value) {
	this->raw_bits_ = roundf(value * (1 << this->fractionnal_bits_));
}

//	DECONSTRUCTORS
Fixed::~Fixed() {
}

//	OVERLOADS
//		Assignment overload
Fixed& Fixed::operator=(const Fixed &assign) {
	if (this != &assign)
		this->raw_bits_ = assign.raw_bits_;
	return *this;
}

//		Comparaison overloads
bool Fixed::operator<(const Fixed &assign) const {
	if (this->raw_bits_ < assign.raw_bits_)
		return true;
	return false;
}

bool Fixed::operator>(const Fixed &assign) const {
	if (this->raw_bits_ > assign.raw_bits_)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &assign) const {
	if (this->raw_bits_ <= assign.raw_bits_)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &assign) const {
	if (this->raw_bits_ >= assign.raw_bits_)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &assign) const {
	if (this->raw_bits_ == assign.raw_bits_)
		return true;
	return false;
}

bool  Fixed::operator!=(const Fixed &assign) const {
	if (this->raw_bits_ != assign.raw_bits_)
		return true;
	return false;
}

//		Increment - decrement overloads
Fixed& Fixed::operator++() {
	this->raw_bits_++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed cpy(*this);
	this->raw_bits_++;
	return cpy;
}

Fixed& Fixed::operator--() {
	this->raw_bits_--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed cpy(*this);
	this->raw_bits_--;
	return cpy;
}

//		Arithmetic overloads
Fixed Fixed::operator+(const Fixed &assign) const {
	return (Fixed(this->toFloat() + assign.toFloat()));
}

Fixed Fixed::operator-(const Fixed &assign) const {
	return (Fixed(this->toFloat() - assign.toFloat()));
}

Fixed Fixed::operator*(const Fixed &assign) const {
	return (Fixed(this->toFloat() * assign.toFloat()));
}

Fixed Fixed::operator/(const Fixed &assign) const {
	return (Fixed(this->toFloat() / assign.toFloat()));
}

//		Stream overloads
std::ostream& operator<<(std::ostream& stream, const Fixed &fixed) {
	stream << fixed.toFloat();
	return (stream);
}

// MEMBER FUNCTIONS
int Fixed::getRawBits() const {
	return this->raw_bits_;
}

void Fixed::setRawBits(int const raw) {
	this->raw_bits_ = raw;
}

int Fixed::toInt() const {
	return (this->raw_bits_ >> this->fractionnal_bits_);
}

float Fixed::toFloat() const {
	return (float)this->raw_bits_ / (1 << this->fractionnal_bits_);
}

Fixed& min(Fixed &assign1, Fixed &assign2) {
	if (assign1 <= assign2)
		return assign1;
	return assign2;
}

const Fixed& Fixed::min(const Fixed &assign1, const Fixed &assign2) {
	if (assign1 <= assign2)
		return assign1;
	return assign2;
}

Fixed& Fixed::max(Fixed &assign1, Fixed &assign2) {
	if (assign1 >= assign2)
		return assign1;
	return assign2;
}

const Fixed& Fixed::max(const Fixed &assign1, const Fixed &assign2) {
	if (assign1 >= assign2)
		return assign1;
	return assign2;
}