#include "Zombie.hpp"

int main(void) {
    Zombie *zombie;

    zombie = zombieHorde(10, "saifeddine");
    for (int i = 0; i < 10; i++)
        zombie->announce();
    delete[] zombie;
    return 0;
}