#pragma once

#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string   _name;
        bool               _signed;
        const int          _gradeToSign;
        const int          _gradeToExecute;

    public:
        // Orthodox Canonical Form
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        virtual ~AForm();
        
        // Assignment operator made protected to prevent slicing
    protected:
        AForm& operator=(const AForm& other);

    public:
        // Getters
        const std::string& getName() const;
        bool    isSigned() const;
        int     getGradeToSign() const;
        int     getGradeToExecute() const;

        // Member functions
        void beSigned(const Bureaucrat& bureaucrat);
        
        // Pure virtual function for execution
        virtual void execute(const Bureaucrat& executor) const = 0;

        // Exception classes
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

    protected:
        void checkExecution(const Bureaucrat& executor) const;

    private:
        void checkGrade(int grade) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);