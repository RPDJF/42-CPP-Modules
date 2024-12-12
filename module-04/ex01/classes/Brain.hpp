#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include "../utils/colors.h"

# define NB_IDEAS 100

class Brain {
	private:
        std::string ideas_[NB_IDEAS];
		unsigned int cursor_;
    public:
        Brain();
        Brain(const Brain& copy);
        ~Brain();
        Brain& operator=(const Brain& assign);
		void addIdea(const std::string& idea);
		const std::string *getIdeas(void) const;
		unsigned int getCursor(void) const;
};

#endif