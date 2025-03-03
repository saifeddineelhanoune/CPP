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
    std::cout << "ScalarConverter Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& converter) {
    (void)converter;
    std::cout << "ScalarConverter Copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter Destructor Called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& converter) {
    (void)converter;
    std::cout << "ScalarConverter Assignment operator called" << std::endl;
    return *this;
}

bool ScalarConverter::isChar(const std::string &literal) {
    return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool ScalarConverter::isInt(const std::string &literal) {
    size_t i = 0;
    
    if (literal.empty())
        return false;
        
    if (literal[0] == '+' || literal[0] == '-')
        i++;
        
    for (; i < literal.length(); i++) {
        if (!std::isdigit(literal[i]))
            return false;
    }
    
    return true;
}

bool ScalarConverter::isFloat(const std::string &literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;
        
    size_t len = literal.length();
    if (len < 2 || literal[len - 1] != 'f')
        return false;
        
    bool hasDecimal = false;
    size_t i = 0;
    
    if (literal[0] == '+' || literal[0] == '-')
        i++;
        
    for (; i < len - 1; i++) {
        if (literal[i] == '.') {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        else if (!std::isdigit(literal[i]))
            return false;
    }
    
    return hasDecimal;
}

bool ScalarConverter::isDouble(const std::string &literal) {
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;
        
    bool hasDecimal = false;
    size_t i = 0;
    
    if (literal.empty())
        return false;
        
    if (literal[0] == '+' || literal[0] == '-')
        i++;
        
    for (; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        else if (!std::isdigit(literal[i]))
            return false;
    }
    
    return hasDecimal;
}

bool ScalarConverter::isPseudoLiteral(const std::string &literal) {
    return (literal == "nan" || literal == "+inf" || literal == "-inf" ||
            literal == "nanf" || literal == "+inff" || literal == "-inff");
}

bool ScalarConverter::isNan(double value) {
    return value != value;
}

bool ScalarConverter::isInf(double value) {
    return value == std::numeric_limits<double>::infinity() ||
           value == -std::numeric_limits<double>::infinity();
}

void ScalarConverter::convertToChar(double value, bool impossible) {
    std::cout << "char: ";
    if (impossible || isNan(value) || isInf(value) || value < 0 || value > 127)
        std::cout << "impossible";
    else if (value < 32 || value > 126)
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(value) << "'";
    std::cout << std::endl;
}

void ScalarConverter::convertToInt(double value, bool impossible) {
    std::cout << "int: ";
    if (impossible || isNan(value) || isInf(value) || 
        value > std::numeric_limits<int>::max() ||
        value < std::numeric_limits<int>::min())
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(value);
    std::cout << std::endl;
}

void ScalarConverter::convertToFloat(double value, bool impossible) {
    std::cout << "float: ";
    if (impossible)
        std::cout << "impossible";
    else {
        if (isNan(value))
            std::cout << "nanf";
        else if (value == std::numeric_limits<double>::infinity())
            std::cout << "+inff";
        else if (value == -std::numeric_limits<double>::infinity())
            std::cout << "-inff";
        else {
            float f = static_cast<float>(value);
            std::cout << f;
            if (f == static_cast<int>(f))
                std::cout << ".0";
            std::cout << "f";
        }
    }
    std::cout << std::endl;
}

void ScalarConverter::convertToDouble(double value, bool impossible) {
    std::cout << "double: ";
    if (impossible)
        std::cout << "impossible";
    else {
        if (isNan(value))
            std::cout << "nan";
        else if (value == std::numeric_limits<double>::infinity())
            std::cout << "+inf";
        else if (value == -std::numeric_limits<double>::infinity())
            std::cout << "-inf";
        else {
            std::cout << value;
            if (value == static_cast<int>(value))
                std::cout << ".0";
        }
    }
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
    double value = 0.0;
    bool impossible = false;
    
    if (isPseudoLiteral(literal)) {
        if (literal == "nan" || literal == "nanf")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf" || literal == "+inff")
            value = std::numeric_limits<double>::infinity();
        else if (literal == "-inf" || literal == "-inff")
            value = -std::numeric_limits<double>::infinity();
    }
    else if (isChar(literal)) {
        value = static_cast<double>(literal[0]);
    }
    else if (isInt(literal)) {
        try {
            long long check = std::atoll(literal.c_str());
            if (check > std::numeric_limits<int>::max() || 
                check < std::numeric_limits<int>::min())
                impossible = true;
            value = static_cast<double>(check);
        } catch (...) {
            impossible = true;
        }
    }
    else if (isFloat(literal)) {
        try {
            std::string temp = literal.substr(0, literal.length() - 1);
            value = std::atof(temp.c_str());
        } catch (...) {
            impossible = true;
        }
    }
    else if (isDouble(literal)) {
        try {
            value = std::atof(literal.c_str());
        } catch (...) {
            impossible = true;
        }
    }
    else {
        try {
            value = std::atof(literal.c_str());
            if (value == 0.0 && literal != "0" && literal != "0.0" && 
                literal != "0.0f" && literal != "+0" && literal != "-0")
                impossible = true;
        } catch (...) {
            impossible = true;
        }
    }

    convertToChar(value, impossible);
    convertToInt(value, impossible);
    convertToFloat(value, impossible);
    convertToDouble(value, impossible);
}