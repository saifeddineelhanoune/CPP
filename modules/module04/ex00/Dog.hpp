/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:45:34 by sel-hano          #+#    #+#             */
/*   Updated: 2024/05/26 17:54:35 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(const std::string& type);
        Dog(const Dog& dog);
        Dog& operator=(const Dog& animal);
        ~Dog();
};