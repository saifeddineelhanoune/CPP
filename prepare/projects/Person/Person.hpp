#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>

class Person {

    protected:
        std::string fullName;
        int age;

    public:
        Person();
        Person(const Person &p);
        Person(const std::string &fn, int age);
        ~Person();
        Person&     operator=(const Person& p);
        std::string getName(void) const;
        int         getAge(void) const;
        void        setName(const std::string &n);
        void        setAge(int age);
        void        introduce() const;
        static int  getAverageAge(const Person &p1, const Person &p2);
        void        writeAge(void) const;
    
    private:
        std::string nationalityID;
        void    printNationalityID(void) const;
};

#endif