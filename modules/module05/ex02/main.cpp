#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat high("high", 1);
        Bureaucrat meduim("meduim", 75);
        Bureaucrat low("low", 150);

        ShrubberyCreationForm shrubbery("dar");
        RobotomyRequestForm roboto("Garden");
        PresidentialPardonForm presidential("room");

        high.signForm(shrubbery);
        meduim.signForm(roboto);
        low.signForm(presidential);

        high.executeForm(shrubbery);
        meduim.executeForm(roboto);
        low.executeForm(presidential);

        std::cout << shrubbery << std::endl;
        std::cout << roboto << std::endl;
        std::cout << presidential << std::endl;

        std::cout << high << std::endl;
        std::cout << meduim << std::endl;
        std::cout << high << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "because" << e.what() << std::endl;
    }
    return 0;
}