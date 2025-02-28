#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        void createShrubbery() const;

    public:
        ShrubberyCreationForm(const std::string& target);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat& executor) const;
};