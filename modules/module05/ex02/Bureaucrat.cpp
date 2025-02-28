#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
    std::cout << "Bureaucrat parametrized constructor called" << std::endl;
    checkGrade(grade);
    this->grade = grade;
}

Bureaucrat::Bureaucrat() : name(""), grade(149) {
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) {
    grade = b.grade;
}

const std::string& Bureaucrat::getName() const {
    return name;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
    if (this != &b)
        grade = b.grade;
    return *this;
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


void    Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << this->name << " Signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << this->name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::setGrade(int grade) {
    this->grade = grade;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}


const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

void    Bureaucrat::checkGrade(int grade) const {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

void    Bureaucrat::executeForm(AForm& form) {
    try {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "because: " << e.what() << std::endl;
    }
}