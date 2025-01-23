#include "classes/Cat.hpp"
#include "classes/Dog.hpp"
#include "classes/WrongCat.hpp"

void basicTests() {
	std::cout << C_CYAN << "Running basic tests" << C_RESET << std::endl;
	Animal alpha("wololo");
	alpha.makeSound();
 	const Animal* meta = new Animal();
	std::cout << "Type " << meta->getType() << std::endl;
	const Animal* dog = new Dog();
	std::cout << "Type " << dog->getType() << std::endl;
	const Animal* cat = new Cat();
	std::cout << "Type " << cat->getType() << std::endl;
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
	std::cout << "Testing copies" << std::endl;
	{
		Animal c1("wolf");
		Animal c2;
		c2 = c1;
		Animal c3(c1);
	}
	std::cout << std::endl;
}

void virtualTests() {
	std::cout << C_CYAN << "Running virtual tests" << C_RESET << std::endl;
	const Animal *animal = new Animal();
	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const Animal *cat = new Cat();
	const WrongAnimal *wrongCat = new WrongCat();
	std::cout << std::endl << "Df animals sounds" << std::endl;
	animal->makeSound();
	wrongAnimal->makeSound();
	std::cout << std::endl << "animals sounds" << std::endl;
	cat->makeSound();
	wrongCat->makeSound();
	std::cout << std::endl << "casted animals sounds" << std::endl;
	(static_cast<const Cat *>(cat))->makeSound();
	(static_cast<const WrongCat *>(wrongCat))->makeSound();
	std::cout << std::endl;
	delete animal;
	delete wrongAnimal;
	delete cat;
	delete wrongCat;
	std::cout << std::endl;
}

int main()
{
	basicTests();
	virtualTests();
	return 0;
}