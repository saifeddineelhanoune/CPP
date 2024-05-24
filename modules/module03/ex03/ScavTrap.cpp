#include "ScavTrap.hpp"

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void    ScavTrap::attack(const std::string& target) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        _energyPoints--;
        std::cout << "ScavTrap attacks " << target << " causing" << _attackDamage << " points of damage!" << std::endl;
    }
}

ScavTrap::ScavTrap() {
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name) {
    std::cout << "ScavTrap param constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = obj;
}

ScavTrap & ScavTrap::operator=(const ScavTrap& obj) {
    std::cout << "ScavTrap Copy assignemet called" << std::endl;
    if (this != &obj) {
        _name = obj._name;
        _hitPoints = obj._hitPoints;
        _attackDamage = obj._attackDamage;
        _energyPoints = obj._energyPoints;
    }
    return *this;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap destructor called" << std::endl;
}

