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
		this->raw_bits_ = assign.getRawBits();
	return *this;
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

std::ostream& operator<<(std::ostream& stream, const Fixed &fixed) {
	stream << fixed.toFloat();
	return (stream);
}