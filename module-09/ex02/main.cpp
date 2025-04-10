#include "utils/colors.h"
#include "./classes/PmergeMe.hpp"

int main(int argc, char **argv) {
	PmergeMe pm(argv, argc);
	std::cout << "Before:\t";
	pm.printSequence();
	clock_t start = clock();
	pm.buildSequence();
	clock_t end = clock();
	double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000;

	std::cout << "After:\t";
	pm.printSequence();
	std::cout << "Time to process a range of " << pm.getSequence().size() << " elements with std::vector : " << duration << " ms" << std::endl;
}