#include <iostream>
#include <stdexcept>

class Person {
    public:
        int age;
        class AgeTooLow : public std::exception {
            public:
                const char *what() const throw() {
                    return "Age too low";
                }
        };
        class AgeTooHigh : public std::exception {
            public:
                const char *what() const throw() {
                    return "Age too high";
                }
        };
        void    checkAge(int age) {
            if (age < 18)
                throw AgeTooLow();
            else if (age > 30)
                throw AgeTooHigh();
        }
};

int main() {
    try {
        Person p;
        p.checkAge(16);
    } catch (...) {
        std::cerr << "Catched: " << std::endl; 
    }
    return 0;
}
