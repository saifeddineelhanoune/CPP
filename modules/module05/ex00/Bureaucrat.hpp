#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat {
    private:
        const   std::string name;
        int     grade;
        Bureaucrat();
    public:
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        // Constructors
        Bureaucrat(const Bureaucrat& b);
        Bureaucrat(const std::string &name, int grade);

        // Accessors
        const std::string& getName() const;
        int getGrade() const;
        void    setGrade(int grade);

        // Methods to modify the grade
        void incrementGrade();
        void decrementGrade();

        //Overload of the assignement operator
        Bureaucrat& operator=(const Bureaucrat& b);

        //Destructor
        ~Bureaucrat();
        //members
    private:
        void    checkGrade(int grade) const;
};
// Overload of the output operator
std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);

