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

class ScalarConverter {
    private:
        ScalarConverter();
        struct ConversionData {
            double value;
            bool isNan;
            bool isInf;
            bool isImpossible;
            std::string literal;
            ConversionData();
        };

        static bool isNan(double value);
        static bool isInf(double value);
        static void handleSpecialCases(ConversionData& data);
        static void handleChar(ConversionData& data);
        static void handleInt(ConversionData& data);
        static void handleFloat(ConversionData& data);
        static void handleDouble(ConversionData& data);
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &scalar);
        ScalarConverter &operator=(ScalarConverter const &obj);
        static void convert(const std::string &literal);
        ~ScalarConverter();
};


