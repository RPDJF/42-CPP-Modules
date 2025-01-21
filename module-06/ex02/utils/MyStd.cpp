#include "./MyStd.hpp"

std::string MyStd::to_string(int value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

std::string MyStd::to_string(float value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

std::string MyStd::to_string(double value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}