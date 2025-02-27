#include "utils/colors.h"
#include "./Iter.hpp"
#include <iostream>

template<typename T>
static void print(T var) {
	std::cout << var << " ";
}

static void basicTests() {
	std::cout << C_YELLOW << "RUNNING BASICTESTS() FOR STRINGS" << C_RESET << std::endl;
	{
		int arr[] = {0, 3, 1, 5, 8,-1, 24};
		iter(arr, 7, &print);
		std::cout << std::endl;
	}
	{
		std::string arr[] = {"hello", "world", "how", "are","you", "today", "?"};
		iter(arr, 7, &print);
		std::cout << std::endl;
	}
	std::cout << C_YELLOW << "ENDING BASICTESTS()" << C_RESET << std::endl << std::endl;
}

static int runTests() {
	basicTests();
	return 0;
}

int main() {
	runTests();
}