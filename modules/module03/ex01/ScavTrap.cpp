#include "ScavTrap.hpp"

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name) {
    _energyPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(): ClapTrap("Scavtrap") {
    std::cout << "ScavTrap Default constructor called " << std::endl;
    _energyPoints = 100;
    _energyPoints = 50;
    attackDamage = 20;
}

void    ScavTrap::attack(const std::string& target) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        _energyPoints--;
        std::cout << "ScavpTrap attacks " << target << " causing "<< _attackDamage <<" points of damage!" << std::endl;
    }
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap copy assignement operator called " << std::endl;
    if (this != &other) {
        _name = other._name;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        _hitPoints = other._hitPoints;
    }
    return *this;
}

ScavTrap::ScavTrap(const ScavTrap& obj){
    _name = obj._name;
    _energyPoints = obj._energyPoints;
    _attackDamage = obj._attackDamage;
    _hitPoints = obj._hitPoints;
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap Destructor called " << std::endl;
}