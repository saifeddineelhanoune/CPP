#pragma once

#include <iostream>

class Bureaucrat {
    private:
        const std::string   _name;
        short                 _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, short grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        short   getGrade() const;
        std::string getName() const;
        class GradeTooHighException : std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : std::exception {
            public:
                virtual const char *what() const throw();
        };
        void    increment();
        void    decrement();
        ~Bureaucrat();
};

std::ostream &operator<< (std::ostream &stream, const Bureaucrat& other) {
    stream << other.getName() << ", bureaucrat grade " \
    << other.getGrade() << "." << std::endl;
    return stream;
}