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

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& converter) {
    if (this != &converter)
        *this = converter;
    return *this;
}

bool    ScalarConverter::isNan(double value) {
    return value != value;
}

bool    ScalarConverter::isNan(double value) {
    return value == std::numeric_limits<double>::infinity() ||
    value == -std::numeric_limits<double>::infinity();
}

void    ScalarConverter::convert(const std::string &literal) {
    
}

bool ScalarConverter::isInf(double value) {
    return value == std::numeric_limits<double>::infinity() ||
    value == -std::numeric_limits<double>::infinity();
}