#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->vectorContainer = other.vectorContainer;
        this->dequeContainer = other.dequeContainer;
    }
    return *this;
}

PmergeMe::~PmergeMe() {
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr, int begin, int end) {
    if (begin >= end) {
        return;
    }
    
    std::vector<std::pair<int, int> > pairs;
    int lonely = -1;
    bool hasLonely = false;

    if ((end - begin + 1) % 2 != 0){
        hasLonely = true;
        lonely = arr[end];
        end--;
    }
    
    for (int i = begin; i <= end; i += 2) {
        if (i + 1 <= end) {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        }
    }

    for (size_t i = 0; i < pairs.size(); i++){
        if (pairs[i].first > pairs[i].second){
            std::swap(pairs[i].first, pairs[i].second);
        }
    }
    
    std::sort(pairs.begin(), pairs.end());

    std::vector<int> main_chain;
    std::vector<int> pend;
    
    for (size_t i = 0; i < pairs.size(); i++){
        main_chain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    main_chain.reserve(arr.size());

    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    while (jacobsthal.back() < static_cast<int>(pend.size())) {
        int n = jacobsthal.size();
        int next = jacobsthal[n-1] + 2 * jacobsthal[n-2];
        jacobsthal.push_back(next);
    }

    if (!pend.empty()) {
        std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pend[0]);
        main_chain.insert(it, pend[0]);
    }

    std::vector<bool> inserted(pend.size(), false);
    inserted[0] = true;

    for (size_t i = 2; i < jacobsthal.size(); i++) {
        int idx = jacobsthal[i];
        
        for (int j = std::min(idx, static_cast<int>(pend.size())) - 1; 
             j >= jacobsthal[i-1]; j--) {
            if (j < static_cast<int>(pend.size()) && !inserted[j]) {
                std::vector<int>::iterator it = std::lower_bound(
                    main_chain.begin(), main_chain.end(), pend[j]);
                main_chain.insert(it, pend[j]);
                inserted[j] = true;
            }
        }
    }

    for (size_t i = 0; i < pend.size(); i++) {
        if (!inserted[i]) {
            std::vector<int>::iterator it = std::lower_bound(
                main_chain.begin(), main_chain.end(), pend[i]);
            main_chain.insert(it, pend[i]);
        }
    }

    if (hasLonely){
        std::vector<int>::iterator it = std::lower_bound(
            main_chain.begin(), main_chain.end(), lonely);
        main_chain.insert(it, lonely);
    }
    
    arr = main_chain;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr, int begin, int end) {
    if (begin >= end) {
        return;
    }
    
    std::deque<std::pair<int, int> > pairs;
    int lonely = -1;
    bool hasLonely = false;

    if ((end - begin + 1) % 2 != 0){
        hasLonely = true;
        lonely = arr[end];
        end--;
    }
    
    for (int i = begin; i <= end; i += 2) {
        if (i + 1 <= end) {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        }
    }

    for (size_t i = 0; i < pairs.size(); i++){
        if (pairs[i].first > pairs[i].second){
            std::swap(pairs[i].first, pairs[i].second);
        }
    }
    
    std::sort(pairs.begin(), pairs.end());

    std::deque<int> main_chain;
    std::deque<int> pend;
    
    for (size_t i = 0; i < pairs.size(); i++){
        main_chain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    while (jacobsthal.back() < static_cast<int>(pend.size())) {
        int n = jacobsthal.size();
        int next = jacobsthal[n-1] + 2 * jacobsthal[n-2];
        jacobsthal.push_back(next);
    }

    if (!pend.empty()) {
        std::deque<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pend[0]);
        main_chain.insert(it, pend[0]);
    }

    std::vector<bool> inserted(pend.size(), false);
    inserted[0] = true;

    for (size_t i = 2; i < jacobsthal.size(); i++) {
        int idx = jacobsthal[i];
        
        for (int j = std::min(idx, static_cast<int>(pend.size())) - 1; 
             j >= jacobsthal[i-1]; j--) {
            if (j < static_cast<int>(pend.size()) && !inserted[j]) {
                std::deque<int>::iterator it = std::lower_bound(
                    main_chain.begin(), main_chain.end(), pend[j]);
                main_chain.insert(it, pend[j]);
                inserted[j] = true;
            }
        }
    }

    for (size_t i = 0; i < pend.size(); i++) {
        if (!inserted[i]) {
            std::deque<int>::iterator it = std::lower_bound(
                main_chain.begin(), main_chain.end(), pend[i]);
            main_chain.insert(it, pend[i]);
        }
    }

    if (hasLonely){
        std::deque<int>::iterator it = std::lower_bound(
            main_chain.begin(), main_chain.end(), lonely);
        main_chain.insert(it, lonely);
    }
    
    arr = main_chain;
}

bool PmergeMe::validateInput(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No numbers provided." << std::endl;
        return false;
    }
    
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        for (size_t j = 0; j < arg.length(); j++) {
            if (j == 0 && arg[j] == '-') {
                std::cerr << "Error: Negative numbers are not allowed." << std::endl;
                return false;
            }
            if (!std::isdigit(arg[j])) {
                std::cerr << "Error: Invalid input." << std::endl;
                return false;
            }
        }
        
        std::istringstream iss(arg);
        long long num;
        iss >> num;
        
        if (num > INT_MAX) {
            std::cerr << "Error: Number too large." << std::endl;
            return false;
        }
    }
    
    return true;
}

bool PmergeMe::parseAndSort(int argc, char** argv) {
    if (!validateInput(argc, argv)) {
        return false;
    }
    
    vectorContainer.reserve(argc - 1);
    
    for (int i = 1; i < argc; i++) {
        int num = std::atoi(argv[i]);
        vectorContainer.push_back(num);
        dequeContainer.push_back(num);
    }
    
    std::cout << "Before: ";
    size_t display_limit = std::min(vectorContainer.size(), size_t(10));
    for (size_t i = 0; i < display_limit; i++) {
        std::cout << vectorContainer[i] << " ";
    }
    if (vectorContainer.size() > display_limit) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
    
    clock_t startVector = clock();
    mergeInsertSortVector(vectorContainer, 0, vectorContainer.size() - 1);
    clock_t endVector = clock();
    double vectorTime = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;
    
    clock_t startDeque = clock();
    mergeInsertSortDeque(dequeContainer, 0, dequeContainer.size() - 1);
    clock_t endDeque = clock();
    double dequeTime = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;
    
    std::cout << "After:  ";
    for (size_t i = 0; i < display_limit; i++) {
        std::cout << vectorContainer[i] << " ";
    }
    if (vectorContainer.size() > display_limit) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << vectorContainer.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) 
              << vectorTime << " us" << std::endl;
              
    std::cout << "Time to process a range of " << dequeContainer.size() 
              << " elements with std::deque : " << std::fixed << std::setprecision(5) 
              << dequeTime << " us" << std::endl;
    
    return true;
}