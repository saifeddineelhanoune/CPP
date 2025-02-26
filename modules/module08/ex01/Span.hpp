#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    // Orthodox Canonical Form
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    ~Span();
    Span &operator=(const Span &other);

    // Member functions
    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    
    // Add a range of numbers
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end) {
        unsigned int count = std::distance(begin, end);
        
        if (_numbers.size() + count > _maxSize) {
            throw std::out_of_range("Cannot add range: would exceed maximum capacity");
        }
        
        _numbers.insert(_numbers.end(), begin, end);
    }
    
    // Getters
    unsigned int getMaxSize() const;
    unsigned int getCurrentSize() const;
};

#endif 