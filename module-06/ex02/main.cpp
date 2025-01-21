#include "classes/A.hpp"
#include "classes/B.hpp"
#include "classes/C.hpp"
#include "utils/colors.h"
#include "utils/MyStd.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Base *generate(void) {
	std::cout << C_CYAN << "Base *generate()> " << C_RESET << "generated " << C_YELLOW;
	int rnd = std::rand() % 3;
	
	switch(rnd) {
		case 0:
			std::cout << "A class" << C_RESET << std::endl;
			return new A();
		case 1:
			std::cout << "B class" << C_RESET << std::endl;
			return new B();
		default:
			std::cout << "C class" << C_RESET << std::endl;
			return new C();
	}
}

void identify(Base *p) {
	std::cout << C_CYAN << "void indentify(Base*)> " << C_RESET << "indentified " << C_YELLOW;
	if (dynamic_cast<A*>(p)) std::cout << "A class" << C_RESET << std::endl;
	else if (dynamic_cast<B*>(p)) std::cout << "B class" << C_RESET << std::endl;
	else if (dynamic_cast<C*>(p)) std::cout << "C class" << C_RESET << std::endl;
	else std::cout << "unknown class" << C_RESET << std::endl;
}

void identify(Base& p) {
	std::cout << C_CYAN << "void indentify(Base&)> " << C_RESET << "indentified " << C_YELLOW;
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A class" << C_RESET << std::endl;
	} catch (const std::exception&) {
		try {
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B class" << C_RESET << std::endl;
		} catch (const std::exception&) {
			try {
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C class" << C_RESET << std::endl;
			} catch (const std::exception&) {
				std::cout << "unkown class" << C_RESET << std::endl;
			}
		}
	}
}

static void basicTests() {
	std::srand(std::time(0));
	std::cout << C_YELLOW << "RUNNING BASICTESTS()" << C_RESET << std::endl;
	{
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;

		base = generate();
		identify(base);
		identify(*base);
		delete base;

		base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	std::cout << C_YELLOW << "ENDING BASICTESTS()" << C_RESET << std::endl << std::endl;
}

static int runTests() {
	basicTests();
	return 0;
}



int main() {
	return runTests();
}