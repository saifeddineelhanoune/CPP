#pragma once

#include "Bureaucrat.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

class Form {
    private:
        const       std::string _name;
        const       int         _gradeSign;
        const       int         _gradeExec;
        bool                    _isSigned;
    public:
    //Exception definition
        class GradeTooHighException : std::exception {
            virtual const char* what() const throw();
        };
        class GradeTooLowException : std::exception {
            virtual const char* what() const throw();
        };
        class FormAlreadySigned : std::exception {
            virtual const char* what() const throw();
        };
    //Constructors
        Form(const std::string &name, int sign, int exec, bool isSigned);
        Form(const Form& f);
    //Overload of the assignement= operator
        Form&   operator=(const Form& f);
    //Accessors
        std::string getName() const;
        int         getGradeSign() const;
        int         getGradeExec() const;
        bool        getIsSigned() const;
    //member functions
        void    beSigned(Bureaucrat& b);
        void    signForm(Bureaucrat& b, Form &f);
    //Destructor
        ~Form();
};