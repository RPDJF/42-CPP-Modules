#include "classes/Cat.hpp"
#include "classes/Dog.hpp"
#include "classes/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* pythondev = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	pythondev->makeSound();
	meta->makeSound();
	return 0;
}