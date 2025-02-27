#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 100);

        Form form("Tax Form", 120, 100);

        bob.incrementGrade();
        std::cout << bob.getGrade() << std::endl;
        bob.decrementGrade();
        std::cout << bob.getGrade() << std::endl;

        bob.signForm(form);

        Form hardForm("Special Form", 50, 50);

        bob.signForm(hardForm);

        std::cout << form << std::endl;

        std::cout << hardForm << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}