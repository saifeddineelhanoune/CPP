#pragma once

#include <iostream>
#include <ostream>
#include <cmath>

class Fixed {
    private:
        int fixed;
        static const int fractional = 8;
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