#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int fixed;
        static const int fractional = 8;
    public:
        Fixed();
        Fixed(int const nb);
        ~Fixed();
        Fixed &operator=(const Fixed &fixed);
        int getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif