#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
    public:
        explicit ShrubberyCreationForm(const std::string& target);
        virtual ~ShrubberyCreationForm();
        void execute(Bureaucrat& executor);
    private:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        void createShrubbery() const;
};