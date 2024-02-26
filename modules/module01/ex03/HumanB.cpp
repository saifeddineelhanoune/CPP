#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->name = name;
}

void HumanB::setWeapon(Weapon weapon) {
    this->w = &weapon;
}

void    HumanB::attack() {
    if (this->w) {
        std::cout << this->name;
        std::cout << " attacks with their ";
        std::cout << this->w->getType() << std::endl;
    }
}