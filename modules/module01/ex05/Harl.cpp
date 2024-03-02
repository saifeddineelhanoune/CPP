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

void    Harl::complain(std::string level) {
    int i = 0;
    std::string flags[4] = {DEBUG, INFO, WARNING, ERROR};
    while(flags[i] != level) {
        if (i > 3){
            i = -1;
            break;
        }
        i++;
    }
    FuncPointer ptr[4] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    if (i == -1) {
        std::cerr << "level not found" << std::endl;
        return ;
    }
    (this->*ptr[i])();
}
