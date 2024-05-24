/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:46:01 by sel-hano          #+#    #+#             */
/*   Updated: 2024/05/24 16:27:02 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
    DiamondTrap ct1;
    DiamondTrap ct2(ct1);
    DiamondTrap ct3;
    
    ct3 = ct1;
    ct1.attack("ScavTrap");
    ct1.takeDamage(6);
    ct1.beRepaired(10);
    return 0;
}