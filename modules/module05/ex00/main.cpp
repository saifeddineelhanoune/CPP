#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;
        
        b1.incrementGrade();
        std::cout << b1 << std::endl;
        b1.incrementGrade();
    } 
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;
        b2.decrementGrade();
        std::cout << b2 << std::endl;
        b2.decrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
