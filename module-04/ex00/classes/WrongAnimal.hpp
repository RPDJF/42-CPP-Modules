#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>
#include "../utils/colors.h"

class WrongAnimal
{
	protected:
		std::string type_;
	public:
		WrongAnimal();
		WrongAnimal(const std::string& type);
		WrongAnimal(const WrongAnimal& copy);
		virtual ~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& assign);
		const std::string& getType() const;
		void makeSound() const;
};

#endif