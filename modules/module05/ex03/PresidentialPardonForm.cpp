#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon", 25, 5), _target(target) {
        std::cout << "Presidential Pardon Constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {
    _target = other._target;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Presidential Pardon Destructor" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat& executor) const {
    checkExecution(executor);
    pardonTarget();
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ppf) {
    AForm::operator=(ppf);
    _target = ppf._target;
    return *this;
}

void PresidentialPardonForm::pardonTarget() const {
    std::cout << _target << " has been pardoned"  << std::endl;
}