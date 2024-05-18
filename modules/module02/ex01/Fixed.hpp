/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:26:19 by sel-hano          #+#    #+#             */
/*   Updated: 2024/04/30 15:26:20 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ostream>
#include <cmath>

class Fixed {
    private:
        int _fixed;
        static const int _fractional = 8;
    public:
        Fixed();
        Fixed(const Fixed &f);
        Fixed(int const nb);
        Fixed(float const nb);
        ~Fixed();
        Fixed   &operator=(const Fixed &fixed);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        int     toInt(void) const;
        float   toFloat(void) const;
};


std::ostream &operator<<(std::ostream& o, const Fixed& f); 