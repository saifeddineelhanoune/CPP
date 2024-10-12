#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(0) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, short grade) : _name(name), _grade(grade) {
    std::cout << "Copy constructor called" << std::endl;
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : _name(b._name), _grade(b._grade) {
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Copy assignement called" << std::endl;
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

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade Too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade Too low";
}

void    Bureaucrat::increment() {
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void    Bureaucrat::decrement() {
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade--;
}