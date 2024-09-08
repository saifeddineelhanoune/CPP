#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    std::cout << "Dog constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other), brain(NULL){
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

void Dog::getIdeas() const{
    brain->getIdeas();
}

void Dog::setIdeas(const std::string& idea, int index){
    brain->setIdeas(idea, index);
}