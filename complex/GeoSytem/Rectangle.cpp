#include "Shape.cpp"
#include "Movable.cpp"

class Rectangle : Shape {
    public:
        Rectangle() {
            std::cout << "Rectangle default constructor called" << std::endl;
        }
        void draw() {
            std::cout << "we're drawing a rectangle" << std::endl;
        }
};

class MovableRectangle : public Rectangle, public Movable {
    public:
        MovableRectangle() {
            std::cout << "MovableRectangle contructor called" << std::endl;
        }
        void move(int x, int y) {
            std::cout << "moving circle with x:" << x << "and y:" << y << std::endl;
        }
};