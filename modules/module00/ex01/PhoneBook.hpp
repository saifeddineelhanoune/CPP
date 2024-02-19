#ifndef PHONEBOOK_H
#define PHONEBOOK_H


#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact	contacts[8];
        int		amount;
    public:
        PhoneBook();
        ~PhoneBook();

        void	show_startup(void);
        void	add_contact(void);
        void	search_contact(void);
        void	show_searched_header(void);
};

#endif