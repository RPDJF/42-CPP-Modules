#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int raw_bits_;
		static const int fractionnal_bits_ = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed& operator=(const Fixed &assign);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif
