/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:16:11 by sel-hano          #+#    #+#             */
/*   Updated: 2024/11/11 13:17:57 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cctype>

class ScalarConverter {
    private:
        // Private constructor to prevent instantiation
        ScalarConverter();
        ScalarConverter(const ScalarConverter &scalar);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &obj);
        
        // Helper methods for type detection
        static bool isChar(const std::string &literal);
        static bool isInt(const std::string &literal);
        static bool isFloat(const std::string &literal);
        static bool isDouble(const std::string &literal);
        static bool isPseudoLiteral(const std::string &literal);
        
        // Conversion methods
        static void convertToChar(double value, bool impossible);
        static void convertToInt(double value, bool impossible);
        static void convertToFloat(double value, bool impossible);
        static void convertToDouble(double value, bool impossible);
        
        // Utility methods
        static bool isNan(double value);
        static bool isInf(double value);

    public:
        static void convert(const std::string &literal);
};


