#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
    public:
        explicit RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        virtual ~RobotomyRequestForm();
        virtual void execute(const Bureaucrat& executor) const;
    private:
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        void performRobotomy() const;
};
