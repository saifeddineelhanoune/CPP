#include "Student.hpp"

Student::Student() {
    std::cout << "Default Constructor called" << std::endl;
}

Student::Student(const std::string& n, int a, const std::string& m) :
Person(n, a), major(m) {
    std::cout << "Param Constructor called" << std::endl;
}

Student::Student(const Student& s) :
Person(s), major(s.major) {
    std::cout << "Copy Constructor called" << std::endl;
}

Student &Student::operator=(const Student& s) {
    if (this != &s) {
        Person::operator=(s);
        major = s.major;
    }
    return *this;
}

std::string Student::getMajor() const { 
    return major; 
}
void Student::setMajor(const std::string& m) { major = m; }

void Student::introduce() const {
    Person::introduce();
    std::cout << "My major is " << major << "." << std::endl;
}
