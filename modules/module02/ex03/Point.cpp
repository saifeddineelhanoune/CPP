#include "Point.hpp"

Point::Point(void) : 
x(0), y(0) {

}

Point::Point(Point const & p) : 
x(p.getX()), y(p.getY()) {

}

Point::Point(float const x, float const y) :
x(x), y(y) {

}

Point::~Point(void) {

}

Point& Point::operator=(Point const & p) {
    (void)p;
	return (*this);
}

Fixed const & Point::getX(void) const {
    return (this->x);
}

Fixed const & Point::getY(void) const {
    return (this->y);
}