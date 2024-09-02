#include <iostream>

class Shape {
    public:
        Shape() {
            std::cout << " Shape default contructor called" << std::endl;
        }
        virtual void draw() = 0;
};