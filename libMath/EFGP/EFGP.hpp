#pragma once

#include <iostream>
#include <string>
#include <cmath>


class EFGP {
    private:
        std::string function;
        int x, a, b, c;
    public:
        EFGP();
        void    readCoefficients() const;
        int getX() const;
        int getA() const;
        int getB() const;
        int getC() const;
        void    setX(int coefficient);
        void    setA(int coefficient);
        void    setB(int coefficient);
        void    setC(int coefficient);
        ~EFGP();
};