#include "Animal.hpp"

// Default constructor
Animal::Animal() : type("Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

// Copy assignment operator
Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

// Virtual destructor
Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

// Accessors
std::string Animal::getType() const {
    return type;
}

void Animal::setType(const std::string& type) {
    this->type = type;
}
