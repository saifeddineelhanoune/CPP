#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const       std::string _name;
        const       int         _gradeSign;
        const       int         _gradeExec;
        bool                    _isSigned;
        AForm();

    public:
        AForm(const AForm& f);
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class FormNotSigned : public std::exception {
            public:
                const char* what() const throw();
        };
        AForm&   operator=(const AForm& f);
        AForm(const std::string &name, int sign, int exec);
        const std::string& getName() const;
        int         getGradeSign() const;
        int         getGradeExec() const;
        bool        getIsSigned() const;
        void    beSigned(const Bureaucrat& b);
        virtual void    execute(Bureaucrat &executor) const = 0;
        virtual ~AForm();

    protected:
        void    checkExecution(Bureaucrat& executor) const;
};

std::ostream&   operator<<(std::ostream& out, const AForm& f);