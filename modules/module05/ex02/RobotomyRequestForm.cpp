#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45), _target(target) {
        std::cout << "Robotomy Request Constructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf) {
    AForm::operator=(rrf);
    _target = rrf._target;
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Roboto Destructor" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat& executor) const{
    checkExecution(executor);
    performRobotomy();
}

void RobotomyRequestForm::performRobotomy() const {
    std::cout << "* Making drilling noises *" << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else 
        std::cout << "Robotomy failed for " << _target << std::endl;
}
