#ifndef DOG_HPP
# define DOG_HPP

#include "./Animal.hpp"
#include "./Brain.hpp"

class Dog: public Animal
{
	private:
		Brain* brain_;
	public:
		Dog();
		Dog(const Dog& copy);
		~Dog();
		Dog& operator=(const Dog& assign);
		void makeSound() const;
		Brain *getBrain() const;
};

#endif