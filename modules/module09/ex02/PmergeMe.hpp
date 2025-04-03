#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <string>
#include <sstream>

class PmergeMe {
private:
    std::vector<int> vectorContainer;
    std::deque<int> dequeContainer;
    
    // Vector implementation
    void mergeInsertSortVector(std::vector<int>& arr, int begin, int end);
    void mergeVector(std::vector<int>& arr, int begin, int mid, int end);
    void insertionSortVector(std::vector<int>& arr, int begin, int end);
    
    // Deque implementation
    void mergeInsertSortDeque(std::deque<int>& arr, int begin, int end);
    void mergeDeque(std::deque<int>& arr, int begin, int mid, int end);
    void insertionSortDeque(std::deque<int>& arr, int begin, int end);
    
    // Validation
    bool validateInput(int argc, char** argv);
    
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    bool parseAndSort(int argc, char** argv);
};

#endif 