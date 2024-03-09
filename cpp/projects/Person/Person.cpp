#include "Student.hpp"

Person::Person() {
    std::cout << "default constructor called" << std::endl;
}

Person::Person(const std::string &fn, int age) :
fullName(fn), age(age) {
    std::cout << "param contructor called" << std::endl;
}

Person::Person(const Person &p) :
fullName(p.fullName), age(p.age) {
    std::cout << "Copy contructor called" << std::endl;
}

Person::~Person() {
    std::cout << "destructor called" << std::endl;
}

Person &Person::operator =(const Person& p) {
    if (this != &p) {
        fullName = p.fullName;
        age = p.age;
    }
    return *this;
}

int         Person::getAge(void) const {
    return this->age;
}

std::string Person::getName(void) const {
    return this->fullName;
}

void        Person::setName(const std::string &name) {
    this->fullName = name;
}

void        Person::setAge(int age) {
    this->age = age;
}

void        Person::introduce(void) const {
    std::cout << "Hello my name is";
    std::cout << " " + fullName;
    std::cout << " and i am ";
    std::cout << age;
    std::cout << "years old" << std::endl;
}

int   Person::getAverageAge(const Person &p1, const Person &p2) {
    return ((p1.age + p2.age) / 2);
} 

void      Person::writeAge(void) const {
    std::cout << "I am " << age;
    std::cout << " years old" << std::endl;
}

void    Person::printNationalityID(void) const {
    std::cout << "My national ID is";
    std::cout << " " + this->nationalityID + " " << std::endl;
}

