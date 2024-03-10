#include "Fixed.hpp"

Fixed::Fixed() : fixed(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int nb) {
    std::cout << "Int constructor called" << std::endl;
    this->fixed = nb * (1 << Fixed::fractional);
}

Fixed::Fixed(const float nb) {
    std::cout << "Float constructor called" << std::endl;
    this->fixed = (int )roundf(nb * (1 << Fixed::fractional));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits(void) const {
    return this->fixed;
}

void    Fixed::setRawBits(int const raw) {
    this->fixed = raw;
}

Fixed &Fixed::operator=(const Fixed& fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixed = fixed.getRawBits();
    return *this;
}

float	Fixed::toFloat( void ) const {
	return ((float)this->fixed / (1 << Fixed::fractional));
}

int		Fixed::toInt( void ) const {
	return (this->fixed >> Fixed::fractional);
}

std::ostream &operator<<( std::ostream& o, const Fixed& f){
    o << f.toFloat();
    return (o);
}

