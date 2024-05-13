#ifndef READLINE_HPP
# define READLINE_HPP

# include <cstring>
# include <string>
# include <iostream>

//	readline: Prints prompt and writes the result to &result
//	returns -1 if an error occures
int	readline(std::string prompt, std::string &result);

#endif