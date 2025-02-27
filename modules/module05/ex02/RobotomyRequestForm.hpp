#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
    public:
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        virtual ~RobotomyRequestForm();
        void execute(Bureaucrat& executor);
    private:
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        void performRobotomy() const;
};
