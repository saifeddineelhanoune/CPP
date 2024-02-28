#include "Harl.hpp"

Harl::Harl() {

}

void    Harl::debug() {
    std::cout << "Harl says: Debug" << std::endl;
}

void    Harl::info() {
    std::cout << "Harl says: Info" << std::endl;
}

void    Harl::warning() {
    std::cout << "Harl says: Warning" << std::endl;
}

void    Harl::error() {
    std::cout << "Harl says: Error" << std::endl;
}

int     search(std::string level) {
    int i = 0;
    std::string flags[4] = {DEBUG, INFO, WARNING, ERROR};
    while(flags[i] != level) {
        if (i > 3)
            return -1;
        i++;
    }
    return i;
}

void    Harl::complain(std::string level) {
    int i = search(level);
    FuncPointer ptr[4] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    switch (i) {
        case 0:
            (this->*ptr[0])();
        case 1:
            (this->*ptr[1])();
        case 2:
            (this->*ptr[2])();
        case 3:
            (this->*ptr[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
