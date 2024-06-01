/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:32:46 by sel-hano          #+#    #+#             */
/*   Updated: 2024/05/26 17:41:23 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("") {
    std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::Animal(const std::string& type) : _type(type) {
    std::cout << "Animal Parametrized Constructor Called" << std::endl;
}

Animal::Animal(const Animal& animal) {
    std::cout << "Copy Constructor Called" << std::endl;
    _type = animal._type;
}

Animal& Animal::operator=(const Animal& animal) {
    if (this != &animal)
        *this = animal;
    std::cout << "Assignement Operator Overload Called" <<  std::endl;
}

Animal::~Animal() {
    std::cout << "Animal Destructor Called" << std::endl;
}

void    Animal::makeSound() const {
    std::cout << "Generic Animal sound" << std::endl;
}

std::string Animal::getType() const {
    return _type;
}

