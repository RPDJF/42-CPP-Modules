#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <vector>
# include "../utils/colors.h"

class Brain {
    private:
        std::vector<std::string> ideas_;
    public:
        Brain();
        Brain(const Brain& copy);
        ~Brain();
        Brain& operator=(const Brain& assign);
};

#endif