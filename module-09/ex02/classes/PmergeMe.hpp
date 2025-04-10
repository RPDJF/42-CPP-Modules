#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <sstream>
# include <iostream>
# include <memory.h>
# include <cmath>
# include "../utils/Whatever.hpp"
# include "../utils/colors.h"

template <typename container>
class PmergeMe {
	private:
		container sequence_;
		container main_;
		container pend_;
		container out_;
		unsigned short step_;
		unsigned short level_;
		unsigned short base_;
		unsigned short element_size_;
		unsigned short temp_;
		unsigned short jacob_lv_;
		unsigned long count_;
		void mergeSort_();
		void pairSwap_(unsigned int a1);
		void insertSort_();
		void init_(char **argv, int argc);
		void insertSortInit_();
		void elementMove(container& src, container& dest, size_t idx, size_t size);
		size_t binarySearch(unsigned int value, size_t range);
		void printStack_(const container& stack) const;
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
		template <typename T>
		bool isEqual(T t1, T t2) {
			this->count_++;
			return (t1 == t2);
		}
		
	public:
		PmergeMe(char **argv, int argc);
		PmergeMe(const PmergeMe&);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe&);
		void buildSequence();
		const container& getSequence() const;
		void printSequence() const ;
		void printStacks() const;
		size_t F(size_t n) const;
		size_t getCount() const;
};

# include "./PmergeMe.tpp"

#endif