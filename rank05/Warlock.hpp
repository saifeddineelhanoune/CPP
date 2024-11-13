#pragma once 

#include <iostream>
#include <string>

class Warlock  {
    private:
        std::string name;
        std::string title;
    public:
        Warlock();
        Warlock(const Warlock& obj);
        Warlock(const std::string& name, const std::string &title);
        std::string&    getName();
        std::string&    getTitle();
};