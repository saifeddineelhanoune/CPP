/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:46:01 by sel-hano          #+#    #+#             */
/*   Updated: 2024/05/23 00:39:23 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
    ScavTrap ct1;
    ScavTrap ct2(ct1);
    ScavTrap ct3;
    
    ct3 = ct1;
    ct1.attack("ScavTrap");
    ct1.takeDamage(6);
    ct1.beRepaired(10);
    return 0;
}