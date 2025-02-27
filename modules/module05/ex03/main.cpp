#include "Intern.hpp"
#include "Bureaucrat.hpp"

void testFormCreation(Intern& intern, const std::string& formName, const std::string& target) {
    std::cout << "\nTesting creation of " << formName << " form:" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    
    AForm* form = intern.makeForm(formName, target);
    if (form) {
        Bureaucrat high("High Level", 1);
        Bureaucrat low("Low Level", 150);

        std::cout << "\nTrying to execute unsigned form:" << std::endl;
        high.executeForm(*form);

        std::cout << "\nTrying to sign with low level bureaucrat:" << std::endl;
        low.signForm(*form);

        std::cout << "\nSigning with high level bureaucrat:" << std::endl;
        high.signForm(*form);

        std::cout << "\nExecuting with high level bureaucrat:" << std::endl;
        high.executeForm(*form);

        delete form;
    }
    std::cout << "----------------------------------------\n" << std::endl;
}

int main() {
    Intern intern;

    // Test all valid form types
    testFormCreation(intern, "robotomy request", "Bender");
    testFormCreation(intern, "presidential pardon", "Zaphod");
    testFormCreation(intern, "shrubbery creation", "Garden");

    // Test invalid form type
    testFormCreation(intern, "invalid form", "Target");

    return 0;
}