#include "classes/Serializer.hpp"
#include "utils/colors.h"
#include "utils/MyStd.hpp"
#include <cfloat>

static void basicTests() {
	std::cout << C_YELLOW << "RUNNING BASICTESTS()" << C_RESET << std::endl;
	{
		Data data = { 1, "rui", "pass" };
		uintptr_t raw = Serializer::serialize(&data);
		Data *ptr = Serializer::deserialize(raw);

		std::cout << raw << std::endl
		<< ptr->id << std::endl << ptr->name << std::endl << ptr->password << std::endl;
		std::cout << C_GREEN << "modifying data thourgh object" << C_RESET << std::endl;
		data.password = "pass2";
		std::cout << ptr->id << std::endl << ptr->name << std::endl << ptr->password << std::endl;
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