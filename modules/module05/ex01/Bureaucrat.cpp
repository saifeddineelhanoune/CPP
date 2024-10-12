#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade) {
    std::cout << "Parametrized constructor called" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat() : name("") {
    std::cout << "Default constructor called" << std::endl;
}

// Getters
const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

// Grade modification methods
void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

// Overload of the stream<< operator and asignement= operator
std::ostream& operator<<(std::ostream &out, const Bureaucrat &b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
    if (this != &b) {
        this->grade = b.grade;
    }
    return *this;
}

//exception handling functions
const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

//Destructor
Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called" << std::endl;
}