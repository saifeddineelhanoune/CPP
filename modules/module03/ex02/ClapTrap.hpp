/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:13:08 by sel-hano          #+#    #+#             */
/*   Updated: 2024/05/24 20:44:48 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap {
    protected:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;
    
    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& obj);
        ClapTrap& operator=(const ClapTrap& obj);
        std::string getName() const;
        void    setName(std::string name);
        int     getHitPoints() const;
        void    setHitPoints(int points);
        int     getEnergyPoints() const;
        void    setEnergyPoints(int points);
        int     getAttackDamage() const;
        void    setAttackDamage(int damage);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ~ClapTrap();
};