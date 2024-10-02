#include "_Shape.cpp"
#include "_Movable.cpp"

class Circle : public Shape {
    public:
        Circle() {
            std::cout << "Circle constructor called" << std::endl;
        }
        void    draw() {
            std::cout << "we're drawing a circle" << std::endl;
        }  
};

class MovableCircle : public Circle, public Movable {
    public:
        MovableCircle() {
            std::cout << "MovableCircle contructor called" << std::endl;
        }
        void move(int x, int y) {
            std::cout << "moving circle with x:" << x << "and y:" << y << std::endl;
        }
};