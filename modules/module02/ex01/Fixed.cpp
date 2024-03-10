#include "Fixed.hpp"

Fixed::Fixed() : fixed(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int nb) {
    std::cout << "Param constructor called" << std::endl;
    this->fixed = nb;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function is called" << std::endl;
    return this->fixed;
}

void    Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function is called" << std::endl;
    this->fixed = raw;
}

Fixed &Fixed::operator = (const Fixed& fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixed = fixed.getRawBits();
    return *this;
}

int     Fixed::toInt(void) const {
    return this->fixed * 256;
}

float   Fixed::toFloat(void) const {
    return this->fixed / 256;
}

