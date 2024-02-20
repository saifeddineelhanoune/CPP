#include "Zombie.hpp"

Zombie* newZombie(std::string name) {

	Zombie *zombie = new Zombie(name);
	if (!zombie)
		return 0;
	return zombie;
}