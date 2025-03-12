#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat high("high", 1);
        Bureaucrat meduim("meduim", 75);
        Bureaucrat low("low", 150);

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm roboto("Garden");
        PresidentialPardonForm presidential("room");

        high.signForm(shrubbery);
        high.signForm(roboto);
        high.signForm(presidential);

        meduim.executeForm(shrubbery);
        // meduim.executeForm(roboto);
        // low.executeForm(presidential);

    } catch (const std::exception &e) {
        std::cerr << "General error: " << e.what() << std::endl;
    }
    return 0;
}