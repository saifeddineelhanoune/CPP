#include "Point.hpp"

Fixed Area(Point const &a, Point const &b, Point const &c) {
    Fixed ax = a.getX();
    Fixed ay = a.getY();
    Fixed bx = b.getX();
    Fixed by = b.getY();
    Fixed cx = c.getX();
    Fixed cy = c.getY();
    return ((ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)));
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed area0 = Area(a, b, c);
    Fixed area1 = Area(a, b, point);
    Fixed area2 = Area(b, c, point);
    Fixed area3 = Area(c, a, point);
    bool res = ((area0 == (area1 + area2 + area3)) && (area1 != 0) && (area2 != 0) && (area3 != 0));
    return (res);
}