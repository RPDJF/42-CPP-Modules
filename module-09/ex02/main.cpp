#include "utils/colors.h"
#include "./classes/PmergeMe.hpp"

int main(int argc, char **argv) {
	PmergeMe pm(argv, argc);
	pm.printSequence();
	pm.buildSequence();
	pm.printSequence();
	(void)pm;
}