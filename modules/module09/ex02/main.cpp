#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    PmergeMe sorter;
    
    if (!sorter.parseAndSort(argc, argv)) {
        return 1;
    }
    
    return 0;
} 