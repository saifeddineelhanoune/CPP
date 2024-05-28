/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:31:04 by sel-hano          #+#    #+#             */
/*   Updated: 2024/05/28 17:36:55 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() :  Animal("") {
    std::cout << "Cat Default Constructor" << std::endl;
}

Cat::Cat(const std::string& type) : Animal(type) {
    std::cout << "Parametrized Constructor Called" << std::endl;
}

Cat::~Cat() { 
    std::cout << "Cat Destructor" << std::endl; 
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
