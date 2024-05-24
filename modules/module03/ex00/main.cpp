/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:46:01 by sel-hano          #+#    #+#             */
/*   Updated: 2024/05/24 15:07:46 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    ClapTrap ct1;
    ClapTrap ct2(ct1);
    ClapTrap ct3;

    ct3 = ct1;
    ct1.attack("ClapTrap");
    ct1.takeDamage(5);
    ct1.beRepaired(10);
    return 0;
}