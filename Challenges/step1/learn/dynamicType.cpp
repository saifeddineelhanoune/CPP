/*

    C++ is known as a statically-typed language, 
    which means the data types of its variables are determined at compile time. 
    However, C++ also provides concepts to have certain level of dynamic typing, 
    which means determining the data types of variables at runtime.

    Here is a brief overview of two ways to achieve dynamic typing in C++:
    void* Pointers
    A void* pointer is a generic pointer that can point to objects of any data type. 
    They can be used to store a reference to any type of object 
    without knowing the specific type of the object.

*/

#include <iostream>

int main() 
{
    int x = 42;
    float y = 3.14f;
    std::string z = "Hello, world!";

    void* void_ptr;

    void_ptr = &x;
    std::cout << "int value: " << *(static_cast<int*>(void_ptr)) << std::endl;

    void_ptr = &y;
    std::cout << "float value: " << *(static_cast<float*>(void_ptr)) << std::endl;

    void_ptr = &z;
    std::cout << "string value: " << *(static_cast<std::string*>(void_ptr)) << std::endl;

    return 0;
}