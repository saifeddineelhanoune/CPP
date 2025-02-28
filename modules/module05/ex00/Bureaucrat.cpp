#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
    std::cout << "Parametrized constructor called" << std::endl;
    checkGrade(grade);
    this->grade = grade;
}

Bureaucrat::Bureaucrat() : name(""), grade(149) {
    std::cout << "Default constructor called" << std::endl;
}

const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade() {
    grade--;
    checkGrade(grade);
}

void Bureaucrat::decrementGrade() {
    grade++;
    checkGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : name(b.name) {
    grade = b.grade;
}

void    Bureaucrat::setGrade(int grade) {
    this->grade = grade;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
    if (this != &b)
        grade = b.grade;
    return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called" << std::endl;
}

void    Bureaucrat::checkGrade(int grade) const {
    if (grade <= 0)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}