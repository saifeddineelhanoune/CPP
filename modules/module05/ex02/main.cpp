#include "main.hpp"

int main() {
    try {
        Bureaucrat high("high", 1);
        Bureaucrat meduim("meduim", 1);
        Bureaucrat Low("low", 1);
        std::string name = "bureaucrat";
        ShrubberyCreationForm shrubbery(name);
        RobotomyRequestForm roboto(name);
        PresidentialPardonForm presidential(name);

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