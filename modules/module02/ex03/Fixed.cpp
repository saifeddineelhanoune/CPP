#include "Fixed.hpp"

Fixed::Fixed() : fixed(0) {
}

Fixed::Fixed(const Fixed &fixed) {
    *this = fixed;
}

Fixed::Fixed(const int nb) {
    this->fixed = nb * (1 << Fixed::fractional);
}

Fixed::Fixed(const float nb) {
    this->fixed = (int )roundf(nb * (1 << Fixed::fractional));
}

Fixed::~Fixed() {
}

int     Fixed::getRawBits(void) const {
    return this->fixed;
}

void    Fixed::setRawBits(int const raw) {
    this->fixed = raw;
}

Fixed &Fixed::operator=(const Fixed& fixed) {
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

bool	Fixed::operator>(Fixed const & r) const {
	return (this->getRawBits() > r.getRawBits());
}

bool	Fixed::operator<(Fixed const & r) const {
	return (this->getRawBits() < r.getRawBits());
}

bool	Fixed::operator>=(Fixed const & r) {
	return (this->getRawBits() >= r.getRawBits());
}

bool	Fixed::operator<=(Fixed const & r) {
	return (this->getRawBits() <= r.getRawBits());
}

bool	Fixed::operator==(Fixed const & r) {
	return (this->getRawBits() == r.getRawBits());
}

bool	Fixed::operator!=(Fixed const & r) {
	return (this->getRawBits() != r.getRawBits());
}

Fixed Fixed::operator*(const Fixed& n) {
  return (
    this->toFloat() * n.toFloat()
  );
}

Fixed Fixed::operator-(const Fixed& n) {
	return (
		Fixed(this->getRawBits() - n.getRawBits())
	);
}

Fixed Fixed::operator+(const Fixed& n) {
  return (
		Fixed(this->getRawBits() + n.getRawBits())
  );
}

Fixed Fixed::operator/(const Fixed& n) {
  return (
    this->toFloat() / n.toFloat()
  );
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
	this->fixed++;
	return (*this);	
}

Fixed &	Fixed::operator--(void) {
	this->fixed--;
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