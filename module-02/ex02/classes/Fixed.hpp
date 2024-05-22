#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int raw_bits_;
		static const int fractionnal_bits_ = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int value);
		Fixed(const float value);
		Fixed& operator=(const Fixed &assign);
		friend bool operator< (const Fixed &assign1, const Fixed &assign2);
		friend bool operator> (const Fixed &assign1, const Fixed &assign2);
		friend bool operator<= (const Fixed &assign1, const Fixed &assign2);
		friend bool operator>= (const Fixed &assign1, const Fixed &assign2);
		friend bool operator== (const Fixed &assign1, const Fixed &assign2);
		friend bool operator!= (const Fixed &assign1, const Fixed &assign2);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static Fixed& min(Fixed &assign1, Fixed &assign2);
		static const Fixed& min(const Fixed &assign1, const Fixed &assign2);
		static Fixed& max(Fixed &assign1, Fixed &assign2);
		static const Fixed& max(const Fixed &assign1, const Fixed &assign2);
};

std::ostream& operator<<(std::ostream& stream, const Fixed &fixed);

#endif
