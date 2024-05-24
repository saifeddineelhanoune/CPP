/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:45:26 by sel-hano          #+#    #+#             */
/*   Updated: 2024/05/24 12:47:20 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
    std::cout << "FragTrap default constructor called" << std::endl;
    return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap parameterized constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const& obj) : ClapTrap(obj) {
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = obj;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap destructor called" << std::endl;
    return ;
}

FragTrap & FragTrap::operator=(FragTrap const& obj) {
	std::cout << "FragTrap copy assignment called" << std::endl;
    if (this != &obj)
    {
        _name = obj._name;
		_hitPoints = obj._hitPoints;
		_attackDamage = obj._attackDamage;
    }
    return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "high fives to Everyone from FragTrap " << _name << std::endl;
}