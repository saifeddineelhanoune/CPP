#include "Span.hpp"

// Constructors and destructor
Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {
    _numbers.reserve(N);
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span::~Span() {}

// Assignment operator
Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

// Member functions
void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::out_of_range("Cannot add number: Span is already full");
    }
    
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (_numbers.size() <= 1) {
        throw std::logic_error("Cannot find span: need at least 2 numbers");
    }
    
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    
    for (size_t i = 1; i < sorted.size(); ++i) {
        unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i-1]);
        if (span < minSpan) {
            minSpan = span;
        }
    }
    
    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() <= 1) {
        throw std::logic_error("Cannot find span: need at least 2 numbers");
    }
    
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    
    return static_cast<unsigned int>(max - min);
}

// Getters
unsigned int Span::getMaxSize() const {
    return _maxSize;
}

unsigned int Span::getCurrentSize() const {
    return _numbers.size();
} 