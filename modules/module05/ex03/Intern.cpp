#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern::~Intern() {}
Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

const Intern::FormCreator Intern::formCreators[] = {
    {"shrubbery creation", &Intern::createShrubberyForm},
    {"robotomy request", &Intern::createRobotomyForm},
    {"presidential pardon", &Intern::createPresidentialForm}
};

AForm* Intern::createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm*  Intern::makeForm(const std::string& formName, const std::string& target) const {
    for (short i = 0; i < 3; i++) {
        if (formName == formCreators[i].formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i].createFunction(target);
        }
    }
    throw UnkownFormException();
}

const char* Intern::UnkownFormException::what() const throw() {
    return "Unknown form type requested";
}