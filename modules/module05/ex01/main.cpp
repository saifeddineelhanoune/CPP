#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 100);  // Bureaucrat with grade 100
        Form form("Tax Form", 120, 100);  // Form requiring grade 120 to sign
        
        // This will succeed because Bob's grade (100) is high enough
        bob.signForm(form);  // Output: "Bob signed Tax Form"
        
        Form hardForm("Special Form", 50, 50);  // Form requiring grade 50 to sign
        
        // This will fail because Bob's grade (100) is too low
        bob.signForm(hardForm);  // Output: "Bob couldn't sign Special Form because Grade too low for form!"
        
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}