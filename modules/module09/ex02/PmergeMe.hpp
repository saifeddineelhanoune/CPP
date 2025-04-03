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
    
    void mergeInsertSortVector(std::vector<int>& arr, int begin, int end);

    void mergeInsertSortDeque(std::deque<int>& arr, int begin, int end);
    
    bool validateInput(int argc, char** argv);
    
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    bool parseAndSort(int argc, char** argv);
};

#endif 