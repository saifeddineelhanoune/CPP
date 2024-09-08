#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* brain;

public:
    Dog();
    Dog(const Dog& other);  // Copy constructor
    ~Dog();
    Dog& operator=(const Dog& other);  // Assignment operator
    void makeSound() const;
	void getIdeas() const;
	void setIdeas(const std::string& idea, int index);
};

