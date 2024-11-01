#include "classes/Cat.hpp"
#include "classes/Dog.hpp"

int main(void) {
    std::vector<Animal *> animals(10);

    for (size_t i = 0; i < animals.size(); i++) {
        if (i % 2)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }

    for (size_t i = 0; i < animals.size(); i++) {
        delete animals[i];
    }
}