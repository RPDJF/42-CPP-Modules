#include "classes/Cat.hpp"
#include "classes/Dog.hpp"
#include "classes/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* pythondev = new WrongCat();
	meta->makeSound();
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	pythondev->makeSound();
	delete meta;
	delete dog;
	delete cat;
	delete pythondev;
	// testing copy
	Animal c1("wolf");
	Animal c2;
	c2 = c1;
	Animal c3(c1);
	return 0;
}