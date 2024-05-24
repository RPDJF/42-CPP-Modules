#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int raw_bits_;
		static const int fractionnal_bits_ = 8;
	public:
	//	CONSTRUCTORS
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int value);
		Fixed(const float value);
	//	DECONSTRUCTORS
		~Fixed();
	//	OVERLOADS
	//		Assignment overload
		Fixed& operator=(const Fixed &assign);
	//		Comparaison overloads (needs friend keyword)
		bool operator<(const Fixed &assign) const;
		bool operator>(const Fixed &assign) const;
		bool operator<=(const Fixed &assign) const;
		bool operator>=(const Fixed &assign) const;
		bool operator==(const Fixed &assign) const;
		bool operator!=(const Fixed &assign) const;
	//		Increment - decrement overloads
		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);
	//		Arithmetic overloads
		Fixed operator+(const Fixed &assign) const;
		Fixed operator-(const Fixed &assign) const;
		Fixed operator*(const Fixed &assign) const;
		Fixed operator/(const Fixed &assign) const;
	// MEMBER FUNCTIONS	
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static Fixed& min(Fixed &assign1, Fixed &assign2);
		static const Fixed& min(const Fixed &assign1, const Fixed &assign2);
		static Fixed& max(Fixed &assign1, Fixed &assign2);
		static const Fixed& max(const Fixed &assign1, const Fixed &assign2);
};

//		Stream overloads
std::ostream& operator<<(std::ostream& stream, const Fixed &fixed);

#endif
