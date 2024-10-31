#include "zombieHorde.hpp"

int	main() {
	Zombie	*zombie;

	zombie = zombieHorde(10, "Gérard");
	for (int i = 0; i < 10; i++)
		zombie[i].annonce();
	delete[] zombie;
}