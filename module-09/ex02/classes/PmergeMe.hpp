#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <sstream>
# include <iostream>
# include <memory.h>
# include <cmath>
# include "../utils/Whatever.hpp"
# include "../utils/colors.h"

class PmergeMe {
	private:
		std::vector<unsigned int> sequence_;
		std::vector<unsigned int> main_;
		std::vector<unsigned int> pend_;
		std::vector<unsigned int> out_;
		unsigned short step_;
		unsigned short level_;
		unsigned short base_;
		unsigned short jacob_lv_;
		unsigned long count_;
		void mergeSort_();
		void pairSwap_(unsigned int a1);
		void insertSort_();
		void init_(char **argv, int argc);
		void insertSortInit_();
		void elementMove(std::vector<unsigned int>& src, std::vector<unsigned int>& dest, size_t idx, size_t size);
		void printStack_(const std::vector<unsigned int>& stack) const;
		template <typename T>
		bool isLess(T t1, T t2) {
			this->count_++;
			return (t1 < t2);
		}
		template <typename T>
		bool isGreater(T t1, T t2) {
			this->count_++;
			return (t1 > t2);	
		}
		
	public:
		PmergeMe(char **argv, int argc);
		PmergeMe(const PmergeMe&);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe&);
		void buildSequence();
		const std::vector<unsigned int>& getSequence() const;
		void printSequence() const ;
		void printStacks() const;

		
};

#endif