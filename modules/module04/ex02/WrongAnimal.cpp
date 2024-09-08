#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const std::string& type) {
	std::cout << "Parameterized constructor called" << std::endl;
	this->type = type;
}

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	this->type = other.type;
	std::cout << "Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
        this->type = other.type;
        std::cout << "Copy assignment operator called" << std::endl;
    }
    return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}

void WrongAnimal::setType(const std::string& type) {
	this->type = type;
}