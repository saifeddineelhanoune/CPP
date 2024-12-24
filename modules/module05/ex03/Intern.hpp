#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern {
    private:

        struct FormCreator {
            std::string formName;
            AForm*  (*createFunction)(const std::string&);
        };
        static AForm* createShrubberyForm(const std::string& target);
        static AForm* createPresidentialForm(const std::string& target); 
        static AForm* createRobotomyForm(const std::string& target);

        static const FormCreator formCreators[];
    public:
        Intern();
        Intern(const Intern &intern);
        ~Intern();
        Intern& operator=(const Intern& intern);
        AForm*  makeForm(const std::string& formName, const std::string& target) const;
        class   UnkownFormException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};