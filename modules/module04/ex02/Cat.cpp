#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
    std::cout << "Cat constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other), brain(NULL){
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

void Cat::getIdeas() const{
    brain->getIdeas();
}

void Cat::setIdeas(const std::string& idea, int index){
    brain->setIdeas(idea, index);
}