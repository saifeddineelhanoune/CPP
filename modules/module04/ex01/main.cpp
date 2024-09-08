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
    Cat* cat1 = new Cat();
    cat1->setIdeas("test", 1);
    Cat* cat2 = new Cat(*cat1);
    delete cat1;
    cat2->getIdeas();
    delete cat2;

    std::cout << "-----------------\n";

    Dog* dog1 = new Dog();
    dog1->setIdeas("test2", 1);
    Dog* dog2 = new Dog(*dog1);
    delete dog1;
    dog2->getIdeas();
    delete dog2;


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
