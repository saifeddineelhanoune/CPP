#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define DEBUG "DEBUG"
#define INFO "INFO"
#define WARNING "WARNING"
#define ERROR "ERROR"

enum numeration {
    d = 1,
    i,
    w,
    e
};

class Harl {
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

    public:
        Harl();
        void complain(std::string level);
};

typedef void(Harl::*FuncPointer)();
int search(std::string level);

#endif