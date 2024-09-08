#include "Cat.hpp" 
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    const WrongAnimal *wrong = new WrongAnimal();
    const WrongAnimal* wrongcat = new WrongCat();

    std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    std::cout << wrong->getType() << " " << std::endl;
    std::cout << wrongcat->getType() << " " << std::endl;
    
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    wrong->makeSound();
    wrongcat->makeSound();

    delete j;
    delete i;
    delete meta;

    delete wrong;
    delete wrongcat;
    return 0;
}