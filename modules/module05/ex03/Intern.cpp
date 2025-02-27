#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createRobotomyRequest(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::createShrubberyCreation(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    struct FormType {
        std::string name;
        AForm* (Intern::*create)(const std::string&);
    };

    const FormType forms[] = {
        {"robotomy request", &Intern::createRobotomyRequest},
        {"presidential pardon", &Intern::createPresidentialPardon},
        {"shrubbery creation", &Intern::createShrubberyCreation}
    };

    for (int i = 0; i < 3; i++) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*forms[i].create)(target);
        }
    }
    
    std::cerr << "Error: Form type '" << formName << "' does not exist" << std::endl;
    return NULL;
} 