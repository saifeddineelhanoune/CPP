#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define DEBUG "debug"
#define INFO "info"
#define WARNING "warning"
#define ERROR "error"


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