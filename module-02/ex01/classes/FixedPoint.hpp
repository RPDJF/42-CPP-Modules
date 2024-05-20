#ifndef FIXEDPOINT_HPP
# define FIXEDPOINT_HPP

# include <iostream>

class FixedPoint {
	private:
		int fixed_point_;
		static const int fractionnal_bits_ = 8;
	public:
		FixedPoint();
		FixedPoint(int fixed_point);
		FixedPoint& operator=(const FixedPoint& assign);
		~FixedPoint();
		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif
