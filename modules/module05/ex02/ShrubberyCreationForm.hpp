#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
    public:
        explicit ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();
        virtual void execute(const Bureaucrat& executor) const;
    private:
        // Private assignment operator to prevent usage
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        void createShrubbery() const;
};