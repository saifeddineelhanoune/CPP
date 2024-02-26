#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w) : w(w) {
    this->name = name;
}

void   HumanA::attack() {
    std::cout << this->name;
    std::cout << " attacks with their ";
    std::cout << this->w.getType() << std::endl;
}