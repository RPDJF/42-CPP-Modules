#include "./Brain.hpp"

static void annonce() {
    std::cout << C_MAGENTA << "(Brain) " << C_RESET;
}

Brain::Brain(): cursor_(0) {
    annonce();
    std::cout << "Default constructor call" << std::endl;
}

Brain::Brain(const Brain& copy): cursor_(copy.cursor_) {
    annonce();
	for (unsigned int i = 0; i < copy.cursor_; i++) {
		this->ideas_[i] = copy.ideas_[i];
	}
    std::cout << "Copy constructor call" << std::endl;
}

Brain::~Brain() {
    annonce();
    std::cout << "Deconstructor call" << std::endl;
}

Brain& Brain::operator=(const Brain& assign) {
	annonce();
	std::cout << "operator= called" << std::endl;
    if (this == &assign) {
        return *this;
	}
	this->cursor_ = assign.cursor_;
    for (unsigned int i = 0; i < this->cursor_; i++) {
		this->ideas_[i] = assign.ideas_[i];
	}
    return *this;
}

void Brain::addIdea(const std::string& idea) {
	if (idea.empty())
		return ;
	this->ideas_[this->cursor_++] = idea;
}

const std::string *Brain::getIdeas(void) const {
	return this->ideas_;
}

unsigned int Brain::getCursor(void) const {
	return this->cursor_;
}
