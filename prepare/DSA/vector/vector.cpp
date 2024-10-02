#include <iostream>
#include <memory> // for std::allocator

template <typename T>
class MyVector {
private:
    T* data;          // Pointer to the array of elements
    size_t size_;     // Current number of elements in the vector
    size_t capacity_; // Total memory allocated (in terms of element count)

    std::allocator<T> alloc; // Allocator to handle memory management

    // Helper function to reallocate memory when more space is needed
    void reallocate(size_t new_capacity) {
        T* new_data = alloc.allocate(new_capacity); // Allocate new memory
        for (size_t i = 0; i < size_; ++i) {
            alloc.construct(new_data + i, std::move(data[i])); // Move old data
            alloc.destroy(data + i); // Destroy the old elements
        }
        alloc.deallocate(data, capacity_); // Free the old memory
        data = new_data;  // Update pointer to new data
        capacity_ = new_capacity; // Update the capacity
    }

public:
    // Default constructor
    MyVector() : data(nullptr), size_(0), capacity_(0) {}

    // Destructor
    ~MyVector() {
        for (size_t i = 0; i < size_; ++i)
            alloc.destroy(data + i); // Destroy each element
        alloc.deallocate(data, capacity_); // Free the allocated memory
    }

    // Push back a new element into the vector
    void push_back(const T& value) {
        if (size_ == capacity_) {
            size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            reallocate(new_capacity); // Allocate more memory when needed
        }
        alloc.construct(data + size_, value); // Construct the new element in place
        ++size_; // Increase size
    }

    // Access an element at a specific index (with bounds check)
    T& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // Get the current size of the vector
    size_t size() const {
        return size_;
    }

    // Get the current capacity of the vector
    size_t capacity() const {
        return capacity_;
    }
};
