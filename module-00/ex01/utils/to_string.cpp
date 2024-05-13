#include "to_string.hpp"

std::string	to_string(int val) {
	std::stringstream	stream;

	stream << val;
	return (stream.str());
}

std::string	to_string(double val) {
	std::stringstream	stream;

	stream << val;
	return (stream.str());
}