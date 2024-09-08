#include "Dog.hpp"

Dog::Dog() {    
	std::cout << "Default Dog Constructor called " << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog &obj) {
    std::cout << "Copy Dog Constructor Called " << std::endl;
    *this = obj;
}

Dog::~Dog( void ) {
    std::cout << "Dog Destructor Called " << std::endl;
}

Dog &Dog::operator=(const Dog &obj) {
    std::cout << "Dog Copy assignement operator called " << std::endl;
    if (this != &obj)
        this->type = obj.type;
    return *this;
}

void Dog::makeSound( void ) const {
    std::cout << "woof" <<  std::endl;
}