#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int fixed;
        static const int fractional = 8;
    public:
        Fixed();
        Fixed(const Fixed &f);
        ~Fixed();
        Fixed(int const nb);
        Fixed   &operator=(const Fixed &fixed);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        int     toInt(void) const;
        float   toFloat(void) const;
};

#endif