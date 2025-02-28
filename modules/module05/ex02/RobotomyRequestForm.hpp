#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& other);
        void performRobotomy() const;
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    public:
        RobotomyRequestForm(const std::string& target);
        ~RobotomyRequestForm();
        void execute(Bureaucrat& executor) const;
};
