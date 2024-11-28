#include "classes/Zombie.hpp"

Zombie	*newZombie(std::string name) {
	Zombie	*output = new Zombie(name);
	return (output);
}