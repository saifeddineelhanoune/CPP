#pragma once

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;

public:
    // Canonical form
    Animal();  // Default constructor
    Animal(const Animal& other);  // Copy constructor
    Animal& operator=(const Animal& other);  // Copy assignment operator
    virtual ~Animal();  // Virtual destructor

    // Pure virtual function
    virtual void makeSound() const = 0;

    // Accessors
    std::string getType() const;
    void setType(const std::string& type);
};

