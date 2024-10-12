#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        // Constructors
        Bureaucrat();
        Bureaucrat(const Bureaucrat& b);
        Bureaucrat(const std::string &name, int grade);

        // Getters
        const std::string& getName() const;
        int getGrade() const;

        // Methods to modify the grade
        void incrementGrade();
        void decrementGrade();
        //Destructor
        ~Bureaucrat();
};
// Overload of the output operator
std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);

