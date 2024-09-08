#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    // Create individual Dog and Cat objects
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    // Test basic functionality
    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    dog->makeSound();
    cat->makeSound();

    // Deallocate the objects
    delete dog;
    delete cat;

    // Test deep copy
    Dog dog1;
    Dog dog2 = dog1;  // Test copy constructor
    dog2 = dog1;  // Test assignment operator

    Cat cat1;
    Cat cat2 = cat1;  // Test copy constructor
    cat2 = cat1;  // Test assignment operator

    // Test array of Animals
    const int N = 4;
    const Animal* animals[N];
    
    for (int i = 0; i < N / 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = N / 2; i < N; i++) {
        animals[i] = new Cat();
    }

    // Delete the array of Animals
    for (int i = 0; i < N; i++) {
        delete animals[i];
    }

    return 0;
}
