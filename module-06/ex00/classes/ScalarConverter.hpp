#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <sstream>
#include "../utils/colors.h"

class ScalarConverter {
	private:
		ScalarConverter() {}
		ScalarConverter(const ScalarConverter& copy) { (void)copy; }
		ScalarConverter& operator=(const ScalarConverter& assign) { (void)assign; return *this; }
		~ScalarConverter() {}
	public:
		static void convert(const std::string&);
};

#endif