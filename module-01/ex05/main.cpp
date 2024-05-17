#include <iostream>
#include <string>
#include "classes/Harl.hpp"

int	main(int argc, char **argv) {
	Harl harl;

	if (argc != 2) {
		std::cerr << "Usage: ./harl [debug/info/warning/error]" << std::endl;
		return 1;
	}
	for(int i = 0; argv[1][i]; i++)
		argv[1][i] = tolower(argv[1][i]);
	harl.complain(argv[1]);
} 