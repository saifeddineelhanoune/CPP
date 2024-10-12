#pragma once
#include "Bureaucrat.hpp"

class Form {
    private:
        const       std::string name;
        const       int         gradeSign;
        const       int         gradeExec;
        bool                    isSigned;
    public:
    //Exception definition
        class GradeTooHighException : std::exception {
            virtual const char* what() const throw();
        };
        class GradeTooLowException : std::exception {
            virtual const char* what() const throw();
        };
    //Constructors
        Form();
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
        void    signForm();
    //Destructor
        ~Form();
};

//Overload the stream<< operator
std::ostream&   operator<<(std::ostream& out, const Form& f);