#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"

class Student : public Person {

    private:
        std::string major;

    public:
        Student();
        Student(const std::string& n, int a, const std::string& m);
        Student(const Student& s);
        Student& operator=(const Student& s);

        std::string getMajor() const;
        void setMajor(const std::string& m);

        void introduce() const;
        
};

#endif