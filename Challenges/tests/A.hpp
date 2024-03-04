#ifndef DESTRUCTOR_CPP
#define DESTRUCTOR_CPP

#include <string>
#include <iostream>

using namespace std;

class A
{
    private:
        string name;
        int age;
    public:
        A(/* args */);
        A(string name, int age);
        ~A();
};


#endif