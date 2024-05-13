#include <string>
#include <iostream>

int	main() {
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout
		<< "Address of string: " << &string << "\n"
		<< "Address held by stringPTR: " << stringPTR << "\n"
		<< "Address held by stringREF: " << &stringREF << "\n"
		<< std::endl;

	std::cout
		<< "Value of string: " << string << "\n"
		<< "Value pointed to by stringPTR: " << *stringPTR << "\n"
		<< "Value pointed to by stringREF: " << stringREF << "\n"
		<< std::endl;
}