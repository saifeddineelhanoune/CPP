/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:46:01 by sel-hano          #+#    #+#             */
/*   Updated: 2024/05/22 20:36:24 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    ClapTrap ct1;
    ClapTrap ct2(ct1);
    ClapTrap ct3;

    ct3 = ct1;
    ct1.attack("ClapTrap");
    ct1.takeDamage(6);
    ct1.beRepaired(10);
    return 0;
}