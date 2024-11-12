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

#include <iosteam>
#include <string>

class ScalarConverter {
    private:
        enum types {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            SPECIAL,
            VALID,
            INVALID
        };
    public:
        ScalarConverter();
        ScalarConverter(const types &t);
        ScalarConverter(const ScalarConverter &scalar);
        ScalarConverter &operator=(ScalarConverter const &obj);
        static void convert();
        static types identify(const std::string &input);
        ~ScalarConverter();
};


