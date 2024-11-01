#ifndef CAT_HPP
# define CAT_HPP

#include "./Animal.hpp"
#include "./Brain.hpp"

class Cat: public Animal
{
	private:
		Brain* brain_;
	public:
		Cat();
		Cat(const Cat& copy);
		~Cat();
		Cat& operator=(const Cat& assign);
		void makeSound() const;
};

#endif