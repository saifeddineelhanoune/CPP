/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:16:11 by sel-hano          #+#    #+#             */
/*   Updated: 2024/10/30 17:16:11 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iosteam>
#include <string>

class ScalarConverter {
    private:
        enum types {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            SPECIAL
        };
    public:
        ScalarConverter();
        ScalarConverter(const types &t);
        ScalarConverter(const ScalarConverter &scalar);
        ScalarConverter &operator=(ScalarConverter const &obj);
        static void convert();
        static void identify(std::string &input);
        ~ScalarConverter();
};


