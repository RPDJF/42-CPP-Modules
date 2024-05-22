#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->raw_bits_ = 0;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	this->raw_bits_ = fixed.getRawBits();
}

Fixed::Fixed(int value) {
	std::cout << "Int constructor called" << std::endl;
	this->raw_bits_ = value << this->fractionnal_bits_;
}

Fixed::Fixed(float value) {
	std::cout << "Float constructor called" << std::endl;
	this->raw_bits_ = std::roundf(value * (1 << this->fractionnal_bits_));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &assign) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign)
		this->raw_bits_ = assign.raw_bits_;
	return *this;
}

bool operator< (const Fixed &assign1, const Fixed &assign2) {
	if (assign1.raw_bits_ < assign2.raw_bits_)
		return true;
	return false;
}

bool operator> (const Fixed &assign1, const Fixed &assign2) {
	if (assign1.raw_bits_ > assign2.raw_bits_)
		return true;
	return false;
}

bool operator<= (const Fixed &assign1, const Fixed &assign2) {
	if (assign1.raw_bits_ <= assign2.raw_bits_)
		return true;
	return false;
}

bool operator>= (const Fixed &assign1, const Fixed &assign2) {
	if (assign1.raw_bits_ >= assign2.raw_bits_)
		return true;
	return false;
}

bool operator== (const Fixed &assign1, const Fixed &assign2) {
	if (assign1.raw_bits_ == assign2.raw_bits_)
		return true;
	return false;
}

bool operator!= (const Fixed &assign1, const Fixed &assign2) {
	if (assign1.raw_bits_ != assign2.raw_bits_)
		return true;
	return false;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->raw_bits_;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
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

std::ostream& operator<<(std::ostream& stream, const Fixed &fixed) {
	stream << fixed.toFloat();
	return (stream);
}