#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int	fixed;
        static int const fractional = 8;

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
        bool	operator>(Fixed const & raw) const;
        bool	operator<(Fixed const & raw) const;
        bool	operator>=(Fixed const & raw);
        bool	operator<=(Fixed const & raw) ;
        bool	operator==(Fixed const & raw) ;
        bool	operator!=(Fixed const & raw);
        Fixed	operator+(Fixed const & raw);
        Fixed	operator-(Fixed const & raw);
        Fixed	operator*(Fixed const & raw);
        Fixed	operator/(Fixed const & raw);
        Fixed	operator++(int);
        Fixed	operator--(int);
        Fixed   &operator++(void);
        Fixed   &operator--(void);
        static Fixed &min(Fixed &f1, Fixed &f2);
        static Fixed &max(Fixed &f1, Fixed &f2);
        static Fixed const &min(Fixed const &f1, Fixed const &f2);
        static Fixed const &max(Fixed const &f1, Fixed const &f2);
};

std::ostream &	operator<<(std::ostream &o, Fixed const &tmp);