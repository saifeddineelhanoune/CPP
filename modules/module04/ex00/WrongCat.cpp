#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "Default WrongCat Constructor called " << std::endl; 
    type = "WrongCat";  
}

WrongCat::WrongCat(const WrongCat &obj) {
    std::cout << "Copy WrongCat Constructor Called " << std::endl;
    *this = obj;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor Called " << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj) {
    std::cout << "WrongCat Copy assignement operator called " << std::endl;
    if (this != &obj)
        this->type = obj.type;
    return *this;
}

void WrongCat::makeSound( void ) const  {
    std::cout << "meow meow" <<  std::endl;
}