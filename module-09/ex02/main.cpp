#include "utils/colors.h"
#include "./classes/PmergeMe.hpp"

int main(int argc, char **argv) {
	PmergeMe pm(argv, argc);
	#if DEBUG
	std::cout << "Original sequence" << std::endl;
	pm.printSequence();
	#endif
	pm.buildSequence();
	#if DEBUG
	std::cout << "Final sequence" << std::endl;
	#endif
	pm.printSequence();
}