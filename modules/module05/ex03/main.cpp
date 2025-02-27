#include "Intern.hpp"

int main() {
    try {
        Intern intern;
        std::string name = "khochrov";
        AForm* s1 = intern.makeForm("shrubbery creation", name);
        AForm* s2 = intern.makeForm("robotomy request", name);
        AForm* s3 = intern.makeForm("presidential pardon", name);
        AForm* s4 = intern.makeForm("", name);

        delete s1;
        delete s2;
        delete s3;

    } catch (const std::exception &e) {
        std::cerr << "Because :" << e.what() <<std::endl;
    }
    return 0;
}