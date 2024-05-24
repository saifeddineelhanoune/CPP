/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:46:01 by sel-hano          #+#    #+#             */
/*   Updated: 2024/05/24 12:49:04 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void) {
    FragTrap ct1;
    FragTrap ct2(ct1);
    FragTrap ct3;
    
    ct3 = ct1;
    ct1.attack("ScavTrap");
    ct1.takeDamage(6);
    ct1.beRepaired(10);
    return 0;
}