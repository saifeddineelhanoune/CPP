/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:28:37 by sel-hano          #+#    #+#             */
/*   Updated: 2024/05/24 16:39:39 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name), __name(name) {
    std::cout << "DiamondTrap parameterized constructor called" << std::endl;
	_hitPoints = this->FragTrap::_hitPoints;
	_energyPoints = this->ScavTrap::_energyPoints;
	_attackDamage = this->FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) {
    this->__name = ClapTrap::_name;
    *this = src;
    return ;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & src) {
    if (this != &src)
        std::cout << "DiamondTrap assignment operator called" << std::endl;
    return *this;
}

void DiamondTrap::attack(std::string const & target) {
	this->ScavTrap::attack(target);
}


void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap name is: " << this->DiamondTrap::__name << std::endl;
	std::cout << "ClapTrap name is: " << this->ClapTrap::_name << std::endl;
}