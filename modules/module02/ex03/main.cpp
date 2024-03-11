#include "Point.hpp"

int main() {
    Point a(3, 2);
    Point b(2, 1);
    Point c(1, 3);
    Point point(2.7, 2.8);
    bool res = bsp(a, b, c, point);
    if (!res)
        std::cout << "out area of triangle" << std::endl;
    else
        std::cout << "in area of triangle" << std::endl;
    return 0;
}