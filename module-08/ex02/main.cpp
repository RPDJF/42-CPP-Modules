#include "utils/colors.h"
#include "classes/MutantStack.hpp"

static void basicTests() {
	std::cout << C_YELLOW << "RUNNING BASICTESTS()" << C_RESET << std::endl;
	{
		MutantStack<int> mutant;
		std::stack<int> stack;

		mutant.push(5);
		mutant.push(1);
		mutant.push(8);
		stack.push(5);
		stack.push(1);
		stack.push(8);
		std::cout << std::endl << C_MAGENTA << "testing std::stack" << C_RESET << std::endl;
		std::cout << "stack at top: " << stack.top() << std::endl;

		std::cout << std::endl << C_MAGENTA << "testing MutantStack" << C_RESET << std::endl;
		std::cout << "mutant at top: " << mutant.top() << std::endl;
		std::cout << "mutant at begin: " << *mutant.begin() << std::endl;
		std::cout << "mutant at end: " << *(mutant.end() - 1) << std::endl;
		for(MutantStack<int>::iterator it = mutant.begin(); it != mutant.end(); it++) {
			std::cout << "mutant at iterator " << it - mutant.begin() << ": " << *it << std::endl;
		}

		std::cout << std::endl << C_MAGENTA << "testing by copy" << C_RESET << std::endl;
		MutantStack<int> mutantCopy(mutant);
		std::cout << "mutantCopy at top: " << mutantCopy.top() << std::endl;
		std::cout << "mutantCopy at begin: " << *mutantCopy.begin() << std::endl;
		std::cout << "mutantCopy at end: " << *(mutantCopy.end() - 1) << std::endl;
		for(MutantStack<int>::iterator it = mutantCopy.begin(); it != mutantCopy.end(); it++) {
			std::cout << "mutantCopy at iterator " << it - mutantCopy.begin() << ": " << *it << std::endl;
		}

		std::cout << std::endl << C_MAGENTA << "testing by assign" << C_RESET << std::endl;
		MutantStack<int> mutantAssign = mutant;
		std::cout << "mutantAssign at top: " << mutantAssign.top() << std::endl;
		std::cout << "mutantAssign at begin: " << *mutantAssign.begin() << std::endl;
		std::cout << "mutantAssign at end: " << *(mutantAssign.end() - 1) << std::endl;
		for(MutantStack<int>::iterator it = mutantAssign.begin(); it != mutantAssign.end(); it++) {
			std::cout << "mutantAssign at iterator " << it - mutantAssign.begin() << ": " << *it << std::endl;
		}
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