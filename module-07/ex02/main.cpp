#include "utils/colors.h"
#include "./Array.hpp"
#include <iostream>

static void basicTests() {
	std::cout << C_YELLOW << "RUNNING BASICTESTS() FOR STRINGS" << C_RESET << std::endl;
	{
		Array<std::string> empty;
		std::cout << C_CYAN << "Array<std::string> empty" << C_RESET << " size : " << empty.size() << std::endl;
		std::cout << "getting out of range value: " << std::endl;
		try {
			std::cout << "empty[0]: " << empty[0] << std::endl;
		} catch (const std::exception& e) {
			std::cerr << C_RED << e.what() << C_RESET << std::endl;
		}
		std::cout << std::endl;
	}
	{
		Array<std::string> hello(2);
		std::cout << C_CYAN << "Array<std::string> hello(2)" << C_RESET << " size : " << hello.size() << std::endl;
		std::cout << "Filling array with " << C_GREEN << "\"Hello\" \"World\"" << C_RESET << std::endl;
		hello[0] = "Hello";
		hello[1] = "world";
		std::cout << "Values: {";
		for(unsigned int i = 0; i < hello.size(); i++) {
			std::cout << "\"" << C_GREEN << hello[i] << C_RESET << "\",";
		}
		std::cout << "}" << std::endl;
		std::cout << "getting out of range value: " << std::endl;
		try {
			std::cout << "hello[2]: " << hello[2] << std::endl;
		} catch (const std::exception& e) {
			std::cerr << C_RED << e.what() << C_RESET << std::endl;
		}
		std::cout << std::endl;
		Array<std::string> goodbye(hello);
		std::cout << C_CYAN << "Array<std::string> goodbye(hello)" << C_RESET << " size : " << goodbye.size() << std::endl;
		std::cout << "changing index [0] only to \"Goodbye\"" << std::endl;
		goodbye[0] = "Goodbye";
		std::cout << "Values: {";
		for(unsigned int i = 0; i < goodbye.size(); i++) {
			std::cout << "\"" << C_GREEN << goodbye[i] << C_RESET << "\",";
		}
		std::cout << "}" << std::endl;
		std::cout << std::endl;
		Array<std::string> sad = hello;
		std::cout << C_CYAN << "Array<std::string> sad = hello" << C_RESET << " size : " << hello.size() << std::endl;
		std::cout << "changing index [0] only to \"Sad\"" << std::endl;
		sad[0] = "Sad";
		std::cout << "Values: {";
		for(unsigned int i = 0; i < sad.size(); i++) {
			std::cout << "\"" << C_GREEN << sad[i] << C_RESET << "\",";
		}
		std::cout << "}" << std::endl;
		std::cout << "Original Values: {";
		for(unsigned int i = 0; i < hello.size(); i++) {
			std::cout << "\"" << C_GREEN << hello[i] << C_RESET << "\",";
		}
		std::cout << "}" << std::endl;
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