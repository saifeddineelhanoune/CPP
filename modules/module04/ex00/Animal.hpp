/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:23:44 by sel-hano          #+#    #+#             */
/*   Updated: 2024/05/26 17:34:01 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal {
    protected:
        std::string _type;
    public:
        Animal();
        Animal(const std::string& type);
        Animal(const Animal& animal);
        Animal& operator= (const Animal& animal);
        ~Animal();
        void    setType(std::string type);
        std::string getType() const;
};