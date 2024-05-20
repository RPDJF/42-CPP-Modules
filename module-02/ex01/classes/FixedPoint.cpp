#include "FixedPoint.hpp"

static const int franctionnal_bits_ = 8;

FixedPoint::FixedPoint() {
	this->fixed_point_ = 0;
}

FixedPoint::FixedPoint(int fixed_point) {
	this->fixed_point_ = fixed_point;
}

FixedPoint& FixedPoint::operator=(const FixedPoint& assign) {
	if (this =! &assign)
		this->fixed_point_ = assign.getRawBits();
	return (*this);
}