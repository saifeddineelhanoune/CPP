#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
    private:
        Weapon &w;
        std::string name;
    public:
        HumanA(std::string name, Weapon &w);
        ~HumanA();
        void    attack();
};

#endif