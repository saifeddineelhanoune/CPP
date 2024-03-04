#include "A.hpp"

A::A() {
    cout << "default contructor called" << endl;
}

A::A(string name, int age) {
    cout << "contructor called" << endl;
    this->name = name;
    this->age = age;
}

A::~A() {
    int i = 0;
    cout << "destructor called" << i << endl;
    i += 1;
}

int main(void) {
    A a1;
    A a2;
    return 0;
}