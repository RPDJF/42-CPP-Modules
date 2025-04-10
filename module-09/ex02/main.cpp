#include "utils/colors.h"
#include "./classes/PmergeMe.hpp"
#include <iomanip>
#include <deque>
#include <vector>

int main(int argc, char **argv) {
	PmergeMe<std::vector<unsigned int> > pm(argv, argc);
	std::cout << "Before:\t";
	pm.printSequence();
	clock_t start = clock();
	pm.buildSequence();
	double duration = clock() - start;

	std::cout << "After:\t";
	pm.printSequence();
	std::cout << "Count of comparators:\t" << (pm.getCount() < pm.G(pm.getSequence().size()) ? C_GREEN : C_RED) << pm.getCount() << C_RESET << std::endl;
	std::cout << "Best case possible:\t" << C_GREEN << pm.F(pm.getSequence().size()) << C_RESET << std::endl;
	std::cout << "Worst case possible:\t" << C_RED << pm.G(pm.getSequence().size()) << C_RESET << std::endl;
	std::cout << "Time to process a range of " << pm.getSequence().size() << " numbers with " << C_CYAN << "std::vector" << C_RESET << ":\t" << std::fixed << std::setprecision(6) << (double)duration / CLOCKS_PER_SEC << "s" << std::endl;
	
	PmergeMe<std::deque<unsigned int> > pm2(argv, argc);
	start = clock();
	pm2.buildSequence();
	duration = clock() - start;
	std::cout << "Time to process a range of " << pm2.getSequence().size() << " numbers with " << C_CYAN << "std::deque" << C_RESET << ":\t" << (double)duration / CLOCKS_PER_SEC << "s" << std::endl;
}