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

// Vector implementation
void PmergeMe::mergeVector(std::vector<int>& arr, int begin, int mid, int end) {
    // Create temp arrays
    int leftSize = mid - begin + 1;
    int rightSize = end - mid;
    
    std::vector<int> leftArr(leftSize);
    std::vector<int> rightArr(rightSize);
    
    // Copy data to temp arrays
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[begin + i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    
    // Merge back
    int i = 0, j = 0, k = begin;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements
    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void PmergeMe::insertionSortVector(std::vector<int>& arr, int begin, int end) {
    for (int i = begin + 1; i <= end; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= begin && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr, int begin, int end) {
    if (end - begin > 10) { // Use merge sort for larger arrays
        if (begin < end) {
            int mid = begin + (end - begin) / 2;
            
            mergeInsertSortVector(arr, begin, mid);
            mergeInsertSortVector(arr, mid + 1, end);
            
            mergeVector(arr, begin, mid, end);
        }
    } else { // Use insertion sort for small arrays
        insertionSortVector(arr, begin, end);
    }
}

// Deque implementation
void PmergeMe::mergeDeque(std::deque<int>& arr, int begin, int mid, int end) {
    // Create temp arrays
    int leftSize = mid - begin + 1;
    int rightSize = end - mid;
    
    std::deque<int> leftArr(leftSize);
    std::deque<int> rightArr(rightSize);
    
    // Copy data to temp arrays
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[begin + i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    
    // Merge back
    int i = 0, j = 0, k = begin;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements
    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void PmergeMe::insertionSortDeque(std::deque<int>& arr, int begin, int end) {
    for (int i = begin + 1; i <= end; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= begin && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr, int begin, int end) {
    if (end - begin > 10) { // Use merge sort for larger arrays
        if (begin < end) {
            int mid = begin + (end - begin) / 2;
            
            mergeInsertSortDeque(arr, begin, mid);
            mergeInsertSortDeque(arr, mid + 1, end);
            
            mergeDeque(arr, begin, mid, end);
        }
    } else { // Use insertion sort for small arrays
        insertionSortDeque(arr, begin, end);
    }
}

bool PmergeMe::validateInput(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No numbers provided." << std::endl;
        return false;
    }
    
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        // Check if all characters are digits
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
        
        // Check for integer overflow
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
    
    // Parse input and store in both containers
    for (int i = 1; i < argc; i++) {
        int num = std::atoi(argv[i]);
        vectorContainer.push_back(num);
        dequeContainer.push_back(num);
    }
    
    // Display unsorted sequence
    std::cout << "Before: ";
    for (size_t i = 0; i < vectorContainer.size(); i++) {
        std::cout << vectorContainer[i] << " ";
    }
    std::cout << std::endl;
    
    // Sort using vector
    clock_t startVector = clock();
    mergeInsertSortVector(vectorContainer, 0, vectorContainer.size() - 1);
    clock_t endVector = clock();
    double vectorTime = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;
    
    // Sort using deque
    clock_t startDeque = clock();
    mergeInsertSortDeque(dequeContainer, 0, dequeContainer.size() - 1);
    clock_t endDeque = clock();
    double dequeTime = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;
    
    // Display sorted sequence
    std::cout << "After:  ";
    for (size_t i = 0; i < vectorContainer.size(); i++) {
        std::cout << vectorContainer[i] << " ";
    }
    std::cout << std::endl;
    
    // Display timing information
    std::cout << "Time to process a range of " << vectorContainer.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) 
              << vectorTime << " us" << std::endl;
              
    std::cout << "Time to process a range of " << dequeContainer.size() 
              << " elements with std::deque : " << std::fixed << std::setprecision(5) 
              << dequeTime << " us" << std::endl;
    
    return true;
} 