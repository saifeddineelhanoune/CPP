#include "Serializer.hpp"
#include <iostream>

int main() {
    // Create and populate a Data object
    Data* original = new Data;
    original->s1 = "Hello";
    original->n = 42;
    original->s2 = "World";
    
    // Print the original data
    std::cout << "Original Data at address " << original << ":" << std::endl;
    std::cout << "s1: " << original->s1 << std::endl;
    std::cout << "n: " << original->n << std::endl;
    std::cout << "s2: " << original->s2 << std::endl;
    
    // Serialize the pointer to Data
    uintptr_t serialized = Serializer::serialize(original);
    std::cout << "\nSerialized value: " << serialized << std::endl;
    
    // Deserialize back to a Data pointer
    Data* deserialized = Serializer::deserialize(serialized);
    
    // Print the deserialized data
    std::cout << "\nDeserialized Data at address " << deserialized << ":" << std::endl;
    std::cout << "s1: " << deserialized->s1 << std::endl;
    std::cout << "n: " << deserialized->n << std::endl;
    std::cout << "s2: " << deserialized->s2 << std::endl;
    
    // Check if the pointers are the same
    std::cout << "\nAre the pointers the same? " 
              << (original == deserialized ? "Yes" : "No") << std::endl;
    
    // Clean up
    delete original;
    
    return 0;
} 