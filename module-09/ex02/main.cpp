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
	std::cout << "Number of comparators:\t" << pm.getCount() << std::endl;
	std::cout << "Minimal count possible:\t" << pm.F(pm.getSequence().size()) << std::endl;
	std::cout << "Time to process a range of " << pm.getSequence().size() << " numbers with std::vector:\t" << std::fixed << std::setprecision(6) << (double)duration / CLOCKS_PER_SEC << " ms" << std::endl;
	
	PmergeMe<std::deque<unsigned int> > pm2(argv, argc);
	start = clock();
	pm2.buildSequence();
	duration = clock() - start;
	std::cout << "Time to process a range of " << pm2.getSequence().size() << " numbers with std::deque:\t" << (double)duration / CLOCKS_PER_SEC << " ms" << std::endl;
}