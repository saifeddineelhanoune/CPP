#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(0) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : _name(b._name), _grade(b._grade) {
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Copy assignement called" std::endl;
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

short   Bureaucrat::getGrade() const {
    return _grade;
}

std::string     Bureaucrat::getName() const {
    return _name;
}