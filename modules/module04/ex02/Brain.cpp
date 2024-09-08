#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}


void Brain::getIdeas() const{
    for (int i = 0; i < 100; i++){
        if (ideas[i] != "")
            std::cout << ideas[i] << std::endl;
    }
}

void Brain::setIdeas(const std::string& idea, int index){
    ideas[index] = idea;
}