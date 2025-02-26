#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef> // For size_t

template <typename T>
class Array {
private:
    T* _elements;
    unsigned int _size;

public:
    // Default constructor - creates an empty array
    Array() : _elements(NULL), _size(0) {}
    
    // Constructor with size - creates an array of n elements initialized by default
    Array(unsigned int n) : _size(n) {
        if (n > 0)
            _elements = new T[n]();
        else
            _elements = NULL;
    }
    
    // Copy constructor
    Array(const Array &other) : _elements(NULL), _size(0) {
        *this = other;
    }
    
    // Destructor
    ~Array() {
        if (_elements)
            delete[] _elements;
    }
    
    // Assignment operator
    Array &operator=(const Array &other) {
        if (this != &other) {
            if (_elements)
                delete[] _elements;
                
            _size = other._size;
            if (_size > 0) {
                _elements = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _elements[i] = other._elements[i];
            } else {
                _elements = NULL;
            }
        }
        return *this;
    }
    
    // Subscript operator
    T &operator[](unsigned int index) {
        if (index >= _size)
            throw std::exception();
        return _elements[index];
    }
    
    // Const subscript operator
    const T &operator[](unsigned int index) const {
        if (index >= _size)
            throw std::exception();
        return _elements[index];
    }
    
    // Size function
    unsigned int size() const {
        return _size;
    }
};

#endif 