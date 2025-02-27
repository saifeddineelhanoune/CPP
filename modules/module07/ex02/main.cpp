#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
    // Test default constructor - empty array
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
    
    // Test parameterized constructor
    Array<int> intArray(5);
    std::cout << "Integer array of size 5 created. Size: " << intArray.size() << std::endl;
    
    // Initialize array elements
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 10;
    }
    
    // Display array elements
    std::cout << "Integer array elements: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Test copy constructor
    Array<int> copiedArray(intArray);
    std::cout << "Copied array size: " << copiedArray.size() << std::endl;
    
    // Modify original array
    intArray[0] = 100;
    
    // Show that the copy is independent
    std::cout << "Original array element 0: " << intArray[0] << std::endl;
    std::cout << "Copied array element 0: " << copiedArray[0] << std::endl;
    
    // Test out of bounds access
    try {
        std::cout << "Attempting to access out of bounds: " << std::endl;
        int value = intArray[10]; // This should throw an exception
        std::cout << "Value: " << value << std::endl; // This should not execute
    } catch (const std::exception& e) {
        std::cout << "Exception caught: Index out of bounds!" << std::endl;
    }
    
    // Test with a different type
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "C++";
    stringArray[2] = "Templates";
    
    std::cout << "String array elements: ";
    for (unsigned int i = 0; i < stringArray.size(); i++) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
} 