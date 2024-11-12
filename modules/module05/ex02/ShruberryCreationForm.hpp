#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : AForm {
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
        ShrubberyCreationForm(const std::string &str);
        virtual void    execute(const Bureaucrat& exec);
        ~ShrubberyCreationForm();
};