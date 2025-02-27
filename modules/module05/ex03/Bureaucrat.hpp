#pragma once

#include <iostream>
#include <exception>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
    private:
        const   std::string name;
        int     grade;
        void    checkGrade(int grade) const;
    public:
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        Bureaucrat();
        Bureaucrat(const Bureaucrat& b);
        Bureaucrat(const std::string &name, int grade);
        const std::string& getName() const;
        int getGrade() const;
        void    setGrade(int grade);
        void incrementGrade();
        void decrementGrade();
        Bureaucrat& operator=(const Bureaucrat& b);
        void    executeForm(AForm& form);
        void    signForm(AForm& form);
        ~Bureaucrat();
};
std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);

