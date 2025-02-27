#include "iter.hpp"
#include <iostream>

// Test functions
template <typename T>
void printElement(T const &element) {
    std::cout << element << " ";
}

void multiplyByTwo(int &num) {
    num *= 2;
}

int main() {
    // Test with integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Original int array: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;
    
    // Modify the array
    iter(intArray, intArrayLength, multiplyByTwo);
    
    std::cout << "Modified int array: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;
    
    // Test with strings
    std::string strArray[] = {"Hello", "C++", "Templates", "are", "powerful"};
    size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);
    
    std::cout << "String array: ";
    iter(strArray, strArrayLength, printElement<std::string>);
    std::cout << std::endl;
    
    return 0;
} 