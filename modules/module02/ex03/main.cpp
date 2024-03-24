#include "Point.hpp"

int main() {
    Point a(3, 2);
    Point b(2, 1);
    Point c(1, 3);
    Point point(2, 2);
    // bool res = bsp(a, b, c, point);
    std::cout << a.getX() << std::endl;
    std::cout << a.getY() << std::endl;
    std::cout << b.getX() << std::endl;
    std::cout << b.getY() << std::endl;
    std::cout << c.getX() << std::endl;
    std::cout << c.getY() << std::endl;
    std::cout << point.getX() << std::endl;
    std::cout << point.getY() << std::endl;
    // if (!res)
    //     std::cout << "out area of triangle " << std::endl;
    // else
    //     std::cout << "in area of triangle" << std::endl;
    return 0;
}