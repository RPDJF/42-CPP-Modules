#include "readline.hpp"

int	readline(std::string prompt, std::string &result)
{
	 std::string input;

    std::cout << prompt;
    if (!std::getline(std::cin, input))
    {
        std::cout << "eof" << std::endl;
        return -1;
    }

    result = input;
    return 0;
}