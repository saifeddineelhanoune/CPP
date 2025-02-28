#include "Intern.hpp"

int main() {
    std::srand(std::time(NULL));
    try {
        Intern intern;
        std::string name = "khochrov";
        AForm* s1 = NULL;
        AForm* s2 = NULL;
        AForm* s3 = NULL;

        try {
            s1 = intern.makeForm("shrubbery creation", name);
            s2 = intern.makeForm("robotomy request", name);
            s3 = intern.makeForm("presidential pardon", name);
            intern.makeForm("", name); // This will throw an exception
        }
        catch (const std::exception& e) {
            // Clean up any forms that were successfully created
            delete s1;
            delete s2;
            delete s3;
            throw; // Re-throw the exception
        }

        // This code won't be reached due to the exception
        delete s1;
        delete s2;
        delete s3;
    }
    catch (const std::exception& e) {
        std::cerr << "Because: " << e.what() << std::endl;
    }
    return 0;
}