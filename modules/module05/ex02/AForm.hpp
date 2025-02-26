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
        AForm(const AForm& f);

    public:
        class GradeTooHighException : std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : std::exception {
            public:
                const char* what() const throw();
        };
        class FormAlreadySigned : std::exception {
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
        virtual void    execute(const Bureaucrat &executor) const = 0;
        ~AForm();

    protected:
        void    checkExecution(const Bureaucrat& executor);
};

std::ostream&   operator<<(std::ostream& out, const AForm& f);