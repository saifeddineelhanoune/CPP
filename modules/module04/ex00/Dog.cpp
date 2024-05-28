/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:49:29 by sel-hano          #+#    #+#             */
/*   Updated: 2024/05/28 17:26:15 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type) {
    std::cout << "Dog Parametrized Constructor Called" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog) {
    std::cout << "Dog Copy Constructor Called" << std::endl;
    *this = dog;
}

Dog& Dog::operator=(const Dog& dog) {
    std::cout << "Dog Assignement Operator Overload Called" << std::endl;
    if (this != &dog)
        *this = dog;
}

void    Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog Destructor Called" << std::endl;
}