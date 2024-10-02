#include "_Shape.cpp"

class Colored : virtual public Shape {
        std::string __color;
    public:
        void    setColor(std::string &color) {
            __color = color;
        }
};

class Textured : virtual public Shape {
        std::string __texture;
    public:
        void    setTexture(std::string &texture) {
            __texture = texture;
        }
};