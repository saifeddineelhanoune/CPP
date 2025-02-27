#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main() {
    // Test with MutantStack
    std::cout << "==== MutantStack Test ====" << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "Elements using iterators: ";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    // Test with reverse iterators
    std::cout << "Elements using reverse iterators: ";
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    
    while (rit != rite) {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;
    
    // Copy to a standard stack
    std::stack<int> s(mstack);
    std::cout << "Copied to standard stack. Size: " << s.size() << std::endl;
    
    // Test with list for comparison
    std::cout << "\n==== std::list Test (for comparison) ====" << std::endl;
    std::list<int> lst;
    
    lst.push_back(5);
    lst.push_back(17);
    
    std::cout << "Back: " << lst.back() << std::endl;
    
    lst.pop_back();
    std::cout << "Size after pop: " << lst.size() << std::endl;
    
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::cout << "Elements using iterators: ";
    std::list<int>::iterator lst_it = lst.begin();
    std::list<int>::iterator lst_ite = lst.end();
    
    ++lst_it;
    --lst_it;
    
    while (lst_it != lst_ite) {
        std::cout << *lst_it << " ";
        ++lst_it;
    }
    std::cout << std::endl;
    
    // Test with a different container type for MutantStack
    std::cout << "\n==== MutantStack with std::vector as container ====" << std::endl;
    MutantStack<int, std::vector<int> > vstack;
    
    vstack.push(42);
    vstack.push(43);
    vstack.push(44);
    
    std::cout << "Elements: ";
    for (MutantStack<int, std::vector<int> >::iterator vit = vstack.begin(); vit != vstack.end(); ++vit) {
        std::cout << *vit << " ";
    }
    std::cout << std::endl;
    
    return 0;
} 