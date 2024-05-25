/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:12:57 by sel-hano          #+#    #+#             */
/*   Updated: 2024/05/24 20:43:07 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name(""), _hitPoints(0), _energyPoints(0), _attackDamage(0) {
    std::cout << "Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name):  _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    this->_name = name;
    std::cout << "Parameterized Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &instance) {
    this->_name = instance._name;
    this->_hitPoints = instance._hitPoints;
    this->_energyPoints = instance._energyPoints;
    this->_attackDamage = instance._attackDamage;
    std::cout << "Copy Constructor Called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj) {
    if (this != &obj) {
        this->_name = obj._name;
        this->_hitPoints = obj._hitPoints;
        this->_energyPoints = obj._energyPoints;
        this->_attackDamage = obj._attackDamage;
    }
    std::cout << "Copy Assignement Called" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        _energyPoints--;
        std::cout << "ClapTrap attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (_hitPoints > 0 && _energyPoints > 0) {
        _hitPoints -= amount;
        std::cout << _name << "Damaged and losed " << amount << " point from the Hit Point, the Energy points now is : "<< _energyPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if ((_hitPoints > 0 ) && (_energyPoints > 0)) {
        _energyPoints--;
        _hitPoints += amount;
        std::cout << _name << "Repairing and get " << amount << " point, the Energy points now is : " << _energyPoints << std::endl;
    }
}

int     ClapTrap::getHitPoints() const {
    return _hitPoints;
}

std::string     ClapTrap::getName() const {
    return _name;
}

int     ClapTrap::getEnergyPoints() const {
    return _energyPoints;
}

int     ClapTrap::getAttackDamage() const {
    return _hitPoints;
}

void    ClapTrap::setName(std::string name) {
    _name = name;
}

void    ClapTrap::setHitPoints(int points) {
    _hitPoints = points;
}

void    ClapTrap::setEnergyPoints(int points) {
    _energyPoints = points;
}

void    ClapTrap::setAttackDamage(int damage) {
    _attackDamage = damage;
}


ClapTrap ::~ClapTrap() {
    std::cout << "Destructor called " << std::endl;
}