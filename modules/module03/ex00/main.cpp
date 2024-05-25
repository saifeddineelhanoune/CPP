/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:46:01 by sel-hano          #+#    #+#             */
/*   Updated: 2024/05/25 19:21:35 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap1;
    ClapTrap claptrap2("Crunchy");

    for (unsigned int i = 0; i < 9; ++i) {
        claptrap1.attack(claptrap2.getName());
        claptrap2.takeDamage(claptrap1.getAttackDamage());

        claptrap2.attack(claptrap1.getName());
        claptrap1.takeDamage(claptrap2.getAttackDamage());
    }
    if (claptrap1.getHitPoints() > claptrap2.getHitPoints()) {
        std::cout << "Winner: ClapTrap " << claptrap1.getName() << " with " << claptrap1.getHitPoints() << " hit points left." << std::endl;
    } else if (claptrap2.getHitPoints() > claptrap1.getHitPoints()) {
        std::cout << "Winner: ClapTrap " << claptrap2.getName() << " with " << claptrap2.getHitPoints() << " hit points left." << std::endl;
    } else {
        std::cout << "Draw between ClapTrap " << claptrap1.getName() << " and ClapTrap " << claptrap2.getName() << "." << std::endl;
    }

    return 0;
}