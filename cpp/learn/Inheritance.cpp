// Diamond Problem in cpp

#include <iostream>
#include <string>

using namespace std;

class Person {
    protected:
        string __firstName;
        string __lastName;
        int __age;
    public:
        Person() { cout << " Person Default Constructor Called" << endl; }
        Person(string first, string last, int age) {
            cout << "Person Constructor Called" << endl;
            __firstName = first;
            __lastName = last;
            __age = age;
        }
};

class Father :  virtual public Person {
    public:
        Father(string first, string last,int age) : Person(first, last, age) {
            cout << "Father Constructor Called" << endl;
        }
};

class Mother : virtual public Person {
    public:
        Mother(string first, string last, int age) : Person(first, last ,age) {
            cout << "Mother Constructor Called" << endl;
        }
};

class Child : public Father, public Mother { 
    public:
        Child(string first, string last, int age) : Mother(first, last, age) , Father(first, last, age) {
            cout << "Child Constructor Called" << endl;
        }
};

int main() {
    Child child("saifeddine", "elhanoune", 24);
}