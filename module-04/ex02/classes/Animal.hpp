#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>
#include "../utils/colors.h"

class Animal
{
    protected:
        std::string type_;
    public:
        Animal();
        Animal(const std::string& type);
        Animal(const Animal& copy);
        virtual ~Animal();
        Animal& operator=(const Animal& assign);
        const std::string& getType() const;
        virtual void makeSound() const = 0;
};

#endif