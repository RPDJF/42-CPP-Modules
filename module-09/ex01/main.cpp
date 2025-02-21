#include "utils/colors.h"
#include <iostream>
#include <stdexcept>
#include <climits>
#include "./classes/RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << C_RED << "./RPN \"your silly math\"" << C_RESET << std::endl;
		return 1;
	}
	RPN rpn(argv[1]);
	try {
		rpn.start();
		std::cout << rpn.getTop() << std::endl;
	} catch(const std::exception& e) {
		std::cerr << C_RED << "Error: " << e.what() << C_RESET << std::endl;
	}
}