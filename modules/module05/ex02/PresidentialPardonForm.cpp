#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon", 25, 5), _target(target) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {
    _target = other._target;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    
}

void PresidentialPardonForm::execute(Bureaucrat& executor) {
    checkExecution(executor);
    pardonTarget();
}

void PresidentialPardonForm::pardonTarget() const {
    std::cout << _target << " has been pardoned"  << std::endl;
}