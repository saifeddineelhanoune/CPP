#include "Animal.hpp"

Animal::Animal(const std::string& type) {
	std::cout << "Parameterized constructor called" << std::endl;
	this->type = type;
}

Animal::Animal() {
	std::cout << "Default constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Destructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->type = other.type;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
        this->type = other.type;
        std::cout << "Copy assignment operator called" << std::endl;
    }
    return *this;
}

std::string Animal::getType() const {
    return this->type;
}

void Animal::setType(const std::string& type) {
	this->type = type;
}