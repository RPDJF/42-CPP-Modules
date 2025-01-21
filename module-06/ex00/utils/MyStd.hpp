#ifndef MYSTD_HPP
# define MYSTD_HPP

#include <string>
#include <ostream>
#include <sstream>

class MyStd {
	public:
		static std::string to_string(int);
		static std::string to_string(double);
		static std::string to_string(float);
};

#endif