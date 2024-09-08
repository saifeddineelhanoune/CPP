#include "Animal.hpp"

Animal::Animal(const std::string& type) {
	std::cout << "Parameterized constructor called" << std::endl;
	this->type = type;
}

Animal::Animal() : type("Animal") {
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	this->type = other.type;
	std::cout << "Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
        this->type = other.type;
        std::cout << "Copy assignment operator called" << std::endl;
    }
    return *this;
}

void Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}

void Animal::setType(const std::string& type) {
	this->type = type;
}