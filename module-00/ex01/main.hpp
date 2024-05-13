#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include "utils/readline.hpp"
# include "classes/PhoneBook.hpp"
# include "classes/Contact.hpp"
# include "utils/colors.h"

# define PROMPT "phonebook> "
# define ERR_WRONG_USAGE C_RED "wrong usage" C_RESET ": type ADD, SEARCH or EXIT\n"
# define ERR_EMPTY_FIELD C_RED "empty field" C_RESET ": a contact can't have empty fields\n"
# define ERR_NO_CONTACTS C_RED "no contacts" C_RESET ": there is no contacts to search for\n"
# define ERR_NOT_AN_IDX C_RED "not an index" C_RESET ": "
# define ERR_LOW_IDX C_RED "index too low" C_RESET ": "
# define ERR_HIGH_IDX C_RED "index too high" C_RESET ": "

#endif