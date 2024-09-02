#include "TexturedColored.cpp"
#include "Circle.cpp"

class TexturedColoredCircle : public MovableCircle, public Colored, public Textured {
    public:
        TexturedColoredCircle() {
            std::cout << "TexturedColoredCircle contructor called" << std::endl;
        }
        void    draw() {
            std::cout << "textured_colored_circle drawn" << std::endl;
        }
        void    move(int x, int y) {
            std::cout << "moving TexturedColoredCircle with x:" << x << "and y:" << y << std::endl;
        }
};