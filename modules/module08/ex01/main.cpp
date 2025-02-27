#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <list>

int main() {
    // Basic test provided in the subject
    std::cout << "==== Basic test ====" << std::endl;
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    
    // Test exceptions
    std::cout << "\n==== Exception tests ====" << std::endl;
    try {
        std::cout << "Trying to add one more number: ";
        sp.addNumber(42);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    Span emptySpan(5);
    try {
        std::cout << "Trying to find span in empty container: ";
        emptySpan.shortestSpan();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    // Test with large number of elements
    std::cout << "\n==== Large test (10,000 numbers) ====" << std::endl;
    Span largeSpan(10000);
    
    // Seed random number generator
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    
    // Add 10,000 random numbers
    for (int i = 0; i < 10000; ++i) {
        largeSpan.addNumber(std::rand() % 100000);
    }
    
    std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
    
    // Test adding range of numbers
    std::cout << "\n==== Range addition test ====" << std::endl;
    Span rangeSpan(10);
    
    std::vector<int> vecNumbers;
    for (int i = 1; i <= 5; ++i) {
        vecNumbers.push_back(i * 10);
    }
    
    rangeSpan.addNumbers(vecNumbers.begin(), vecNumbers.end());
    std::cout << "Added " << rangeSpan.getCurrentSize() << " numbers via range" << std::endl;
    
    std::list<int> listNumbers;
    for (int i = 6; i <= 10; ++i) {
        listNumbers.push_back(i * 10);
    }
    
    rangeSpan.addNumbers(listNumbers.begin(), listNumbers.end());
    std::cout << "Added " << rangeSpan.getCurrentSize() << " numbers total" << std::endl;
    
    std::cout << "Shortest span: " << rangeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << rangeSpan.longestSpan() << std::endl;
    
    // Test range overflow
    try {
        std::cout << "\nTrying to add too many numbers via range: ";
        std::vector<int> tooMany(5, 100);
        rangeSpan.addNumbers(tooMany.begin(), tooMany.end());
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
} 