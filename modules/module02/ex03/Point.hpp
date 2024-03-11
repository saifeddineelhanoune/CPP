#pragma once

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;

    public:
        Point(void);
        Point(Point const & p);
        Point(float const x, float const y);
        ~Point();

        Point& operator=(Point const & p);

        Fixed const & getX(void) const;
        Fixed const & getY(void) const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);