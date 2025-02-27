#pragma once

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        virtual ~Intern();

        AForm* makeForm(const std::string& formName, const std::string& target);
    
    private:
        typedef AForm* (Intern::*FormCreator)(const std::string& target);
        AForm* createRobotomyRequest(const std::string& target);
        AForm* createPresidentialPardon(const std::string& target);
        AForm* createShrubberyCreation(const std::string& target);
}; 