#include "_Shape.cpp"

class Triangle : public Shape {
    public:
        Triangle() {
            std::cout << "Triangle default contructor called" << std::endl;
        }
        void    draw() {
            std::cout << "we're drawing triangle" << std::endl;
        }
};