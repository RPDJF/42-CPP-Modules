#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <sstream>
//#include <cstdint>
#include "../utils/colors.h"

typedef struct s_data {
	unsigned long long id;
	std::string name;
	std::string password;
} Data;

typedef unsigned long uintptr_t;

class Serializer {
	private:
		Serializer() {}
		Serializer(const Serializer& copy) { (void)copy; }
		Serializer& operator=(const Serializer& assign) { (void)assign; return *this; }
		~Serializer() {}
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif