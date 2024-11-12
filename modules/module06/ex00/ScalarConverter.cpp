/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:16:22 by sel-hano          #+#    #+#             */
/*   Updated: 2024/11/11 13:16:46 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter Default constructor called" std::endl;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter Destructor Called" << std::endl;
}

void    ScalarConverter::identify(const std::string &input) {
    if ((input == "nan" || input == "nanf" \
    || input == "+inf" || input == "+inff" \
    || input == "-inf" || input == "-inff" \
    || input == "inf" || input == "inff"))
        return SPECIAL;
    else if (input.length() == 1 && !isdigit(input.at(0)))
        return CHAR;
    for (unsigned int i = 0; i < input.length(); i++) {
        
    }
}