#pragma once

#include <iostream>
#include <exception>
#include <string>
#include "Form.hpp"

class Form;

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
        void    signForm(Form& form);
        ~Bureaucrat();
};
std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);

