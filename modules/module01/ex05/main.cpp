#include "Harl.hpp"

int main(void) {
    Harl *harl = new Harl();
    harl->complain(DEBUG);
    harl->complain(INFO);
    harl->complain(WARNING);
    harl->complain(ERROR);
    delete harl;
    return 0;
}