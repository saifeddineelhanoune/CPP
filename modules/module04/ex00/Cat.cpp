#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Default Cat Constructor called " << std::endl; 
    type = "Cat";  
}

Cat::Cat(const Cat &obj) {
    std::cout << "Copy Cat Constructor Called " << std::endl;
    *this = obj;
}

Cat::~Cat() {
    std::cout << "Cat Destructor Called " << std::endl;
}

Cat &Cat::operator=(const Cat &obj) {
    std::cout << "Cat Copy assignement operator called " << std::endl;
    if (this != &obj)
        this->type = obj.type;
    return *this;
}

void Cat::makeSound( void ) const  {
    std::cout << "meow meow" <<  std::endl;
}