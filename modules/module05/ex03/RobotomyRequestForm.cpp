#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45), _target(target) {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    checkExecution(executor);
    performRobotomy();
}

void RobotomyRequestForm::performRobotomy() const {
    std::cout << "* Making drilling noises *" << std::endl;
    if (std::rand() % 2) std::cout << _target << " has been robotomized successfully!" << std::endl;
    else std::cout << "Robotomy failed for " << _target << std::endl;
}
