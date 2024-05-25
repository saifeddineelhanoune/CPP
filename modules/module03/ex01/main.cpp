/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:46:01 by sel-hano          #+#    #+#             */
/*   Updated: 2024/05/24 20:26:18 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
    ScavTrap ct1;
    ScavTrap ct2(ct1);
    ScavTrap ct3;
    
    ct3 = ct1;
    ct1.attack("ScavTrap");
    ct1.takeDamage(300);
    ct1.beRepaired(200);
    std::cout << "---->" << std::endl;
    ct1.guardGate();
    return 0;
}