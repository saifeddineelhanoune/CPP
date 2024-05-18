/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:18:35 by sel-hano          #+#    #+#             */
/*   Updated: 2024/04/30 15:18:36 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0) {
}

Fixed::Fixed(const Fixed &fixed) {
    *this = fixed;
}

Fixed::Fixed(const int nb) {
    _fixed = nb << _fractional;
}

Fixed::Fixed(const float nb) {
    _fixed = (int )roundf(nb * (1 << _fractional));
}

Fixed::~Fixed() {
	
}

int     Fixed::getRawBits(void) const {
    return _fixed;
}

void    Fixed::setRawBits(int const raw) {
    _fixed = raw;
}

Fixed &Fixed::operator=(const Fixed& fixed) {
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

std::ostream &operator<<( std::ostream& o, const Fixed& f){
    o << f.toFloat();
    return (o);
}

bool	Fixed::operator>(Fixed const & r) const {
	return (_fixed > r._fixed);
}

bool	Fixed::operator<(Fixed const & r) const {
	return (_fixed < r._fixed);
}

bool	Fixed::operator>=(Fixed const & r) {
	return (_fixed >= r._fixed);
}

bool	Fixed::operator<=(Fixed const & r) {
	return (_fixed <= r._fixed);
}

bool	Fixed::operator==(Fixed const & r) {
	return (_fixed == r._fixed);
}

bool	Fixed::operator!=(Fixed const & r) {
	return (_fixed != r._fixed);
}

Fixed Fixed::operator*(const Fixed& n) {
	Fixed	tmp;
	tmp._fixed = _fixed * n._fixed;
	tmp._fixed >>= _fractional;
	return tmp;
}

Fixed Fixed::operator-(const Fixed& n) {
	Fixed	tmp;
	tmp._fixed = _fixed - n._fixed;
	return tmp;
}

Fixed Fixed::operator+(const Fixed& n) {
	Fixed	tmp;
	tmp._fixed = _fixed + n._fixed;
	return tmp;
}

Fixed Fixed::operator/(const Fixed& n) {
	if (n._fixed != 0)
		return Fixed(_fixed / n._fixed);
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp = *this;
	++(*this);
	return (tmp);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp = *this;
	--(*this);
	return (tmp);
}

Fixed &	Fixed::operator++(void) {
	_fixed++;
	return (*this);	
}

Fixed &	Fixed::operator--(void) {
	_fixed--;
	return (*this);
}

Fixed & Fixed::min(Fixed &f1, Fixed &f2) {
	return (f1 < f2 ? f1 : f2);
}

Fixed const & Fixed::min(Fixed const &f1, Fixed const &f2) {
	return (f1 < f2 ? f1 : f2);
}

Fixed & Fixed::max(Fixed &f1, Fixed &f2) {
	return ((f1 > f2) ? f1 : f2);
}

Fixed const & Fixed::max(Fixed const &f1, Fixed const &f2) {
	return ((f1 > f2) ? f1 : f2);
} 