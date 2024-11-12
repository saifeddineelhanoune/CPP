#pragma once

#include "Bureaucrat.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

class AForm {
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
        AForm();
        AForm(const std::string &name, int sign, int exec);
        AForm(const AForm& f);
    //Overload of the assignement= operator
        AForm&   operator=(const AForm& f);
    //Accessors
        std::string getName() const;
        int         getGradeSign() const;
        int         getGradeExec() const;
        bool        getIsSigned() const;
    //member functions
        void    beSigned(Bureaucrat& b);
        void    signForm(Bureaucrat& b, AForm &f);
    //Destructor
        ~AForm();
};