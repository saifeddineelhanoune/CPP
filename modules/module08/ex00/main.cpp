#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

template <typename T>
void testContainer(T &container, int value) {
    std::cout << "Searching for value " << value << ": ";
    
    try {
        typename T::iterator result = easyfind(container, value);
        std::cout << "Found at position: " 
                  << std::distance(container.begin(), result) << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    // Test with vector
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    
    std::cout << "Vector test:" << std::endl;
    testContainer(vec, 20);
    testContainer(vec, 50);
    
    // Test with list
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);
    
    std::cout << "\nList test:" << std::endl;
    testContainer(lst, 15);
    testContainer(lst, 45);
    
    // Test with deque
    std::deque<int> deq;
    deq.push_back(7);
    deq.push_back(17);
    deq.push_back(27);
    deq.push_back(37);
    
    std::cout << "\nDeque test:" << std::endl;
    testContainer(deq, 27);
    testContainer(deq, 47);
    
    return 0;
} 