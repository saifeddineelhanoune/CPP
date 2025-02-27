#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat high("high", 1);
        Bureaucrat meduim("meduim", 75);
        Bureaucrat low("low", 150);

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm roboto("Garden");
        PresidentialPardonForm presidential("room");

        high.signForm(shrubbery);
        meduim.signForm(roboto);
        low.signForm(presidential);

        high.executeForm(shrubbery);
        meduim.executeForm(roboto);
        low.executeForm(presidential);
    } catch (...) {
        std::cerr << "Exception caught" << std::endl;
    }
    return 0;
}