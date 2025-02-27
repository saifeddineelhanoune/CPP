#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Generate a random Base-derived object
Base* generate(void) {
    // Seed the random number generator if first call
    static bool first = true;
    if (first) {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        first = false;
    }
    
    int random = std::rand() % 3;
    
    switch (random) {
        case 0:
            std::cout << "Generated an A object" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated a B object" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated a C object" << std::endl;
            return new C();
        default:
            return NULL; // Should never happen
    }
}

// Identify the type using pointer
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// Identify the type using reference (without using pointers)
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast&) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast&) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::bad_cast&) {}
    
    std::cout << "Unknown type" << std::endl;
}

int main() {
    // Test with multiple random objects
    for (int i = 0; i < 5; ++i) {
        std::cout << "\n=== Test " << i + 1 << " ===" << std::endl;
        
        Base* obj = generate();
        
        std::cout << "Identifying using pointer: ";
        identify(obj);
        
        std::cout << "Identifying using reference: ";
        identify(*obj);
        
        delete obj;
    }
    
    return 0;
} 