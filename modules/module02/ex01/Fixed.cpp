/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:26:16 by sel-hano          #+#    #+#             */
/*   Updated: 2024/05/20 16:44:04 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int nb) {
    std::cout << "Int constructor called" << std::endl;
        _fixed = nb << _fractional;
}

Fixed::Fixed(const float nb) {
    std::cout << "Float constructor called" << std::endl;
    _fixed = (int )roundf(nb * (1 << _fractional));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits(void) const {
    return _fixed;
}

void    Fixed::setRawBits(int const raw) {
    _fixed = raw;
}

Fixed &Fixed::operator=(const Fixed& fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        _fixed = fixed._fixed;
    return *this;
}

float	Fixed::toFloat( void ) const {
	return ((float)_fixed / (1 << _fractional));
}

int		Fixed::toInt( void ) const {
	return (_fixed >> _fractional);
}

std::ostream &operator<<( std::ostream& o, const Fixed& f) {
    o << f.toFloat();
    return (o);
}
