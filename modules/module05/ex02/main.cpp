#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat high("high", 1);
        Bureaucrat meduim("meduim", 75);
        Bureaucrat Low("low", 150);

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm roboto("Garden");
        PresidentialPardonForm presidential("room");

        high.signForm(shrubbery);
        meduim.signForm(roboto);
        Low.signForm(presidential);

        shrubbery.execute(high);
        roboto.execute(Low);
        presidential.execute(meduim);
    } catch (const std::exception &e) {
        std::cerr << "Because :" << e.what() <<std::endl;
    }
    return 0;
}