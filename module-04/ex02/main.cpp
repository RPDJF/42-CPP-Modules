#include "classes/Cat.hpp"
#include "classes/Dog.hpp"

int main(void) {
	// Animal alpha;
	Animal *animals[20];

    for (size_t i = 0; i < 20; i++) {
		std::cout << "construction loop n°" << i << std::endl;
        if (i % 2) {
			Cat *cat = new Cat();
            animals[i] = cat;
			cat->getBrain()->addIdea("cat");
		}
        else {
            Dog *dog = new Dog();
            animals[i] = dog;
			dog->getBrain()->addIdea("dog");
		}
		if (i && !(i % 3)) {
			if (i % 2) {
				Cat *cat = dynamic_cast<Cat*>(animals[i]);
				*cat = *(dynamic_cast<Cat*>(animals[i - 2]));
				cat->getBrain()->addIdea("hey");
			}
			else {
				Dog *dog = dynamic_cast<Dog*>(animals[i]);
				delete dog;
				dog = new Dog(*dynamic_cast<Dog*>(animals[i - 2]));
				dog->getBrain()->addIdea("ilkay <3");
				animals[i] = dog;
			}
		}
		std::cout << std::endl;
    }

	for(int i = 0; i < 20; i++) {
		std::cout << "print loop n°" << i << std::endl;
		if (i % 2) {
			Cat *cat = dynamic_cast<Cat*>(animals[i]);
			const std::string *ideas = cat->getBrain()->getIdeas();
			for (unsigned int j = 0; j < cat->getBrain()->getCursor(); j++) {
				std::cout << "> " << ideas[j] << std::endl;
			}
		}
		else {
			Dog *dog = dynamic_cast<Dog*>(animals[i]);
			const std::string *ideas = dog->getBrain()->getIdeas();
			for (unsigned int j = 0; j < dog->getBrain()->getCursor(); j++) {
				std::cout << "> " << ideas[j] << std::endl;
			}
		}
	}

    for (size_t i = 0; i < 20; i++) {
        delete animals[i];
    }
}
