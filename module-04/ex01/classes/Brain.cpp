#include "./Brain.hpp"

static void annonce() {
    std::cout << C_MAGENTA << "(Brain) " << C_RESET;
}

Brain::Brain(): ideas_(100) {
    annonce();
    std::cout << "Default constructor call" << std::endl;
}

Brain::Brain(const Brain& copy) {
    annonce();
    this->ideas_ = copy.ideas_;
    std::cout << "Copy constructor call" << std::endl;
}

Brain::~Brain() {
    annonce();
    std::cout << "Deconstructor call" << std::endl;
}

Brain& Brain::operator=(const Brain& assign) {
    if (this == &assign)
        return *this;
    this->ideas_ = assign.ideas_;
    return *this;
}
