#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <sstream>
# include <iostream>
# include <memory.h>
# include <cmath>
# include "../utils/Whatever.hpp"

class PmergeMe {
	private:
		std::vector<unsigned int> sequence_;
		void pairSort_(unsigned int level);
		void pairSwap_(unsigned int a1, unsigned int base);
		void init_(char **argv, int argc);
		
	public:
		PmergeMe(char **argv, int argc);
		PmergeMe(const PmergeMe&);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe&);
		void buildSequence();
		const std::vector<unsigned int>& getSequence() const;
		void printSequence() const ;

		
};

#endif