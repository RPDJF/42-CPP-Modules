#include "classes/Cat.hpp"
#include "classes/Dog.hpp"
#include "classes/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const Animal* pythondev = new WrongCat();
	std::cout << "type: " << meta->getType() << " " << std::endl;
	std::cout << "type: " << cat->getType() << " " << std::endl;
	std::cout << "type: " << dog->getType() << " " << std::endl;
	std::cout << "type: " << pythondev->getType() << " " << std::endl;
	meta->makeSound();
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	pythondev->makeSound();
	delete meta;
	delete dog;
	delete cat;
	delete pythondev;
	return 0;
}