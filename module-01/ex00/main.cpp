#include "newZombie.hpp"
#include "randomChump.hpp"

int	main() {
	Zombie	*zombie;

	zombie = newZombie("Steve");
	randomChump("Kazuya");
	delete zombie;
}