#pragma once

#include <iostream>
#include <string>

class Employee {
    protected:
        std::string _name;
        int _id;
    public:
        Employee();
        Employee(const std::string &name, int id) : _name(name), _id(id);
        virtual ~Employee();
        virtual void displayRole() const;
};