#include "Harl.hpp"

int main(int ac, char *av[]) {
    Harl *harl = new Harl();
    if (ac == 2)
        return harl->complain(av[1]), delete harl, 0;
    else
        return std::cout << "level not found" << std::endl, delete harl, 1;
}