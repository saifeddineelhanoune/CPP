#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const       std::string _name;
        const       int         _gradeSign;
        const       int         _gradeExec;
        bool                    _isSigned;
        Form();
        Form(const Form& f);
    public:
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        Form&   operator=(const Form& f);
        Form(const std::string &name, int sign, int exec);
        const std::string& getName() const;
        int         getGradeSign() const;
        int         getGradeExec() const;
        bool        getIsSigned() const;
        void    beSigned(const Bureaucrat& b);
        ~Form();
};

std::ostream&   operator<<(std::ostream& out, const Form& f);