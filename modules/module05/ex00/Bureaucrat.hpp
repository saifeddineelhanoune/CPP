#pragma once

#include <stdexcept>
#include <string>
#include <iostream>

class Bureaucrat {
    private:
        const   std::string name;
        int     grade;
        Bureaucrat();
        Bureaucrat(const Bureaucrat& b);
    public:
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        Bureaucrat(const std::string &name, int grade);
        const std::string& getName() const;
        int     getGrade() const;
        void    setGrade(int grade);
        void incrementGrade();
        void decrementGrade();
        Bureaucrat& operator=(const Bureaucrat& b);
        ~Bureaucrat();
    private:
        void    checkGrade(int grade) const;
};
std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);

