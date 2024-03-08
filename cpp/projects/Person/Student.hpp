#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"

class Student : public Person {

    private:
        std::string major;

    public:
        Student(const std::string &fn, int age, const std::string &major);
        std::string getMajor(void) const;
        void setMajor(const std::string &major);
        std::string getMajor(void) const;
        void setMajor(const std::string &major);
        void    introduce() const override;
        
};

#endif