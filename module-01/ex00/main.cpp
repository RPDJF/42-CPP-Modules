#include "classes/Zombie.hpp"

int	main() {
	Zombie	*zombie;

	zombie = newZombie("Steve");
	randomChump("Kazuya");
	delete zombie;
}